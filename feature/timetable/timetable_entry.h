/* 
 * File:   timetable_entry.h
 * Author: Jannis Diekmann
 *
 * Created on 31. Januar 2021, 12:22
 */

#ifndef TIMETABLE_ENTRY_H
#define	TIMETABLE_ENTRY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdint.h>


// Id to select a specific timetable    
typedef uint8_t timetable_id;


/*************************************************************************
Struct:   timetable_entry
Purpose:  store the time, duration and the interval for a timed event
**************************************************************************/
struct timetable_entry{
    // time of first activation from event
    time_t  next_event;
    
    // time till deactivation
    time_t  duration_of_activation;
    
    // time till next activation
    time_t  interval;
    
    // last function executed was activation function
    uint8_t is_active           :1;
    
    // event_id;
    uint8_t event_id            :7;
    
    
    //repeat times? maybe _interval == NULL => do only once?
};


#ifdef	__cplusplus
}
#endif

#endif	/* TIMETABLE_ENTRY_H */

