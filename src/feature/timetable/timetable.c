#ifndef UNIT_TEST

#include "timetable.h"
#include <time.h>
#include "../../driver/eeprom/eeprom.h"
#include "../Log/Log.h"

#include "event_collection.h"

#define TIMETABLE_MAX_ENTRIES 8//16

// Global:

/*************************************************************************
Array:    timetable[]
Purpose:  store multiple timed events (timetable_entries)
**************************************************************************/
struct timetable_entry* timetable = 0;

//current number of entries in timetable | also write pos for new entries
uint8_t timetable_entries_count = 0;

/*enum error_types {

};


void error_handle() {

}*/

bool timetable_init(){
    for(timetable_id n = 0; n < TIMETABLE_MAX_ENTRIES; ++n){
        // buffer to store timetable in
        struct timetable_entry temp_timetable_entry = {0};
        
        // entries in eeprom?
        if(!eeprom_get_data_by_identifier(&eeprom_internal, (struct data_identifier){eeprom_data_type_timetable_entry, n}, &temp_timetable_entry)) break;
        
        // re-allocate storage for the new timetable entry
        struct timetable_entry* new_mem = (struct timetable_entry*)realloc(timetable, (timetable_entries_count + 1) * sizeof(struct timetable_entry));
    
        // failed to get memory
        if (0 == new_mem) return 0;     //ERROR NOT ENOUGH RAM

        // all fine update global timetable ptr
        timetable = new_mem;
        
        // store recovered entry in global timetable
        timetable[timetable_entries_count] = temp_timetable_entry;
        
        // increment next free slot ptr
        ++timetable_entries_count;
    }
    // timetable restored successfully
    return 1;
}


// IMPLEMENTATION:

/*************************************************************************
Function: tm_compare()
Purpose:  compare two timetable_entry structs
Input:    timetable_entry structs to compare
Returns:  1: equal
          0: not equal
**************************************************************************/
bool timetable_entry_compare(const struct timetable_entry* entry_1,
                             const struct timetable_entry* entry_2
                             ){
    return (entry_1->next_event                == entry_2->next_event             &&
            entry_1->duration_of_activation    == entry_2->duration_of_activation &&
            entry_1->interval                  == entry_2->interval               &&
            entry_1->is_active                 == entry_2->is_active              &&
            entry_1->event_id                  == entry_2->event_id
            );
}

/*************************************************************************
Function: timetable_check_doubled()
Purpose:  check if given entry is already existing
Input:    entry to check
Returns:  1 an equal entry already exists
          0 no equal entry found
**************************************************************************/
bool timetable_check_doubled(struct timetable_entry* entry) {
    for (timetable_id n = 0; n < timetable_entries_count; ++n) {
        //entry already exists
        if (timetable_entry_compare(&timetable[n], entry)) return 1;
    }

    //entry not found
    return 0;
}


/*************************************************************************
Function: timetable_add()
Purpose:  add an entry to the timetable
Input:    first event time, interval to repeat event
Returns:  1: success (entry stored successfully)
          0: failure (not enough free space or doubled or eeprom write fail)
**************************************************************************/
bool timetable_add(time_t first_activation, time_t duration, time_t interval, uint8_t event_id){
    //already to much entries
    if(timetable_entries_count == TIMETABLE_MAX_ENTRIES) return 0;
    
    //make a new entry with the given values
    struct timetable_entry new_entry = {.next_event             = first_activation,
                                        .duration_of_activation = duration,
                                        .interval               = interval,
                                        .event_id               = event_id,
                                        .is_active              = 0
    };

    if (timetable_check_doubled(&new_entry)) return 0;

    //re-allocate storage for the new timetable entry
    struct timetable_entry* new_mem = (struct timetable_entry*)realloc(timetable, (timetable_entries_count + 1) * sizeof(struct timetable_entry));
    
    //failed to get memory
    if (0 == new_mem) return 0;

    //all fine update ptr
    timetable = new_mem;
    
    //activate as soon, as possible
    if(first_activation == 0) new_entry.next_event = time(0);
    
    //store it at the next free slot in timetable
    timetable[timetable_entries_count] = new_entry;
    
    //write to eeprom
    eeprom_update_data_by_identifier(&eeprom_internal, &new_entry, (struct data_identifier){eeprom_data_type_timetable_entry, timetable_entries_count});
    
    //increment next free slot ptr
    ++timetable_entries_count;
    
    // Store current entries count as additional data
    struct Log_data log_current_timers = {.data = {timetable_entries_count}};
    
    // Make log entry
    Log_storeEntry(Log_tag_debug, Log_code_timetable_entry_added, &log_current_timers);
    
    //entry stored successfully
    return 1;
}

/*************************************************************************
Function: timetable_delete()
Purpose:  delete the timetable_entry pointed by entry_index
Input:    index to the desired entry
Returns:  0 fail during relloc or eeprom write
          1 success
**************************************************************************/
bool timetable_delete(timetable_id entry_index){
    //call deactivation function from dedicated event
    timetable_events[timetable[entry_index].event_id].fun_ptr_deactivate();
    
    //index cannot be higher then existing entries count
    if (entry_index >= timetable_entries_count) return 0;
    
    //decrement global entries count
    --timetable_entries_count;

    //not the last one?
    if (entry_index != timetable_entries_count) {
        //copy timer at last position
        struct timetable_entry* last_entry = &timetable[timetable_entries_count];
    
        //overwrite desired entry with the entry from last position
        timetable[entry_index] = *last_entry;
        
        //write to eeprom
        eeprom_update_data_by_identifier(&eeprom_internal, last_entry, (struct data_identifier){eeprom_data_type_timetable_entry, entry_index});
    }
    
    //delete in eeprom by using the delete bit
    eeprom_delete_data_by_identifier(&eeprom_internal, (struct data_identifier){eeprom_data_type_timetable_entry, timetable_entries_count});
    
    //release the last block
    struct timetable_entry* new_mem = (struct timetable_entry*)realloc(timetable, timetable_entries_count * sizeof(struct timetable_entry));
    
    //nullptr?
    if (0 == new_mem) return 0;             //ERROR DURING MEMORY ALLOCATION

    //all fine update ptr
    timetable = new_mem;
    
    struct Log_data Log_data = timetable_make_log_data();
    
    // Make log entry
    Log_storeEntry(Log_tag_debug, Log_code_timetable_entry_deleted, &Log_data);
    
    //success
    return 1;
}

/*************************************************************************
Function: timetable_get()
Purpose:  return a pointer to an entry pointed by entry_index
          to ensure the entry is valid stay below timetable_count_used_entries()
Input:    index to the desired entry
Returns:  pointer to the requested entry or nullptr
**************************************************************************/
struct timetable_entry* timetable_get(timetable_id entry_index){
    //prevent restricted access
    if (entry_index >= timetable_entries_count) return 0;

    //return desired entry
    return &timetable[entry_index];
}




// Log:

#include <string.h>

struct Log_data timetable_make_log_data(){
    // Store current entries count as additional data
    struct Log_data log_current_timers = {.data = {timetable_entries_count}};
    
    return log_current_timers;
}

void timetable_log_data_parse(struct Log_data* data, char* res){
    strcat(res, "current entries: ");
    strcat(res, itoa(data->data[0], 0, 10));
}

#endif // UNIT_TEST
