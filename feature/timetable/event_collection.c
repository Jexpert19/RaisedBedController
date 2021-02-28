#include "event_collection.h"


#include "../../driver/IO/RBCTL_hardware.h"
#include "../../driver/pump.h"


struct unit timetable_events[] = {
    //pumps[0]
    
    #if     RBCTL_PUMPS_COUNT >= 1
    mk_unit(PUMP1),
    #elif   RBCTL_PUMPS_COUNT >= 2
    mk_unit(PUMP2),
    #elif   RBCTL_PUMPS_COUNT >= 3
    mk_unit(PUMP3),
    #elif   RBCTL_PUMPS_COUNT >= 4
    mk_unit(PUMP4)
    #endif
};
