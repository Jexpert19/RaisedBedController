#ifndef UNIT_TEST

#include "event.h"
#include "timetable_entry.h"
#include "event_collection.h"
#include "timetable.h"
#include <time.h>
#include <stdbool.h>

void check_timetable_event(struct timetable_entry * entry){
    time_t current_time = time(0);
    if(entry->next_event <= current_time){
        //event delayed?
        while(entry->next_event <= current_time){
            entry->next_event += entry->duration_of_activation + entry->interval;
        }
        
        //go to last event in the past
        entry->next_event -= (entry->duration_of_activation + entry->interval);
        
        //to late for specific event
        if(entry->is_active){
            if(entry->next_event + entry->interval <= current_time){
                entry->next_event += entry->interval;
                entry->is_active = false;
            }
        }
        else {
            if(entry->next_event + entry->duration_of_activation <= current_time){
                entry->next_event += entry->duration_of_activation;
                entry->is_active = true;
            }
        }
        
        //activation
        if(!entry->is_active){
            
            //execute activation function
            timetable_events[entry->event_id].fun_ptr_activate();
            
            //single event
            if(entry->duration_of_activation == 0){

                //next event: activation
                entry->next_event += entry->interval;
            }
                
            else {
                //set active flag bit
                entry->is_active = true;
                
                //next event: deactivation
                entry->next_event += entry->duration_of_activation;
            }
        }
            
        //deactivation
        else {
                
        //execute deactivation function
        timetable_events[entry->event_id].fun_ptr_deactivate();
            
        //clear active flag bit
        entry->is_active = false;
             
        //next event: activation
        entry->next_event += entry->interval;
        
        }           
    }
}

void timetable_events_run(){
    for(timetable_id n = 0; n < timetable_entries_count; ++n){
        check_timetable_event(timetable_get(n));
    }
}

#endif // UNIT_TEST
