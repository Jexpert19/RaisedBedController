/* 
 * File:   event_collection.h
 * Author: Jannis Diekmann
 *
 * Created on 31. Januar 2021, 11:56
 */

#ifndef EVENT_COLLECTION_H
#define	EVENT_COLLECTION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../driver/IO/RBCTL_hardware.h"

enum timetable_event_ids{
    event_id_pump,
};

extern struct unit timetable_events[];
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* EVENT_COLLECTION_H */

