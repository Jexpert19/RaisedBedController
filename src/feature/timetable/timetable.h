/* 
 * File:   timetable.h
 * Author: Jannis Diekmann
 *
 * Created on 1. Oktober 2020, 20:30
 */

#ifndef TIMETABLE_H
#define	TIMETABLE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <time.h>                       // time_t, time(), ...
#include <stdbool.h>                    // bool
#include <stdint.h>                     // uint8_t
#include "timetable_entry.h"            // struct timetable_entry

//current number of entries in timetable | also write pos for new entries
extern uint8_t timetable_entries_count;  

//init
bool timetable_init();

/*************************************************************************
Function: timetable_add()
Purpose:  add an entry to the timetable
Input:    first event time, interval to repeat event
Returns:  1: success (entry stored successfully)
          0: failure (not enough free space or doubled)
**************************************************************************/
bool timetable_add(time_t first_activation, time_t duration, time_t interval, uint8_t event_id);

/*************************************************************************
Function: timetable_delete()
Purpose:  delete the timetable_entry pointed by entry_index
Input:    index to the desired entry
Returns:  0 fail during relloc
          1 success
**************************************************************************/
bool timetable_delete(timetable_id entry_index);

/*************************************************************************
Function: timetable_get()
Purpose:  return a pointer to an entry pointed by entry_index
          to ensure the entry is valid stay below timetable_count_used_entries()
Input:    index to the desired entry
Returns:  pointer to the requested entry
**************************************************************************/
struct timetable_entry* timetable_get(timetable_id entry_index);



// Log:

struct Log_data timetable_make_log_data();

void timetable_log_data_parse(struct Log_data* data, char* res);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMETABLE_H */

