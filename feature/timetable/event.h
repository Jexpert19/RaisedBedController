/* 
 * File:   event.h
 * Author: Jannis Diekmann
 *
 * Created on 31. Januar 2021, 11:58
 */

#ifndef EVENT_H
#define	EVENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "timetable.h"
    
void check_timetable_event(struct timetable_entry * entry);

void timetable_events_run();




#ifdef	__cplusplus
}
#endif

#endif	/* EVENT_H */

