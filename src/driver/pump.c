/*
 * pump.c
 *
 * Created: 17.05.2020 21:00:17
 *  Author: Jannis Diekmann
 */
 
#ifndef UNIT_TEST

#include "pump.h"

#include "IO/RBCTL_hardware.h"


#define mk_unit_function(name) void name ## _turn_on() {IO_WRITE(IO_ ## name, 1);  }\
                               void name ## _turn_off(){IO_WRITE(IO_ ## name, 0);  }\
                               void name ## _init()    {IO_SET_OUTPUT(IO_ ## name);}


#if     RBCTL_PUMPS_COUNT >= 1
mk_unit_function(PUMP1)
#elif   RBCTL_PUMPS_COUNT >= 2
mk_unit_function(PUMP2)
#elif   RBCTL_PUMPS_COUNT >= 3
mk_unit_function(PUMP3)
#elif   RBCTL_PUMPS_COUNT >= 4
mk_unit_function(PUMP4)
#endif

        
struct unit pumps[] = {
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
        
        
void pump_init(void){
    #if     RBCTL_PUMPS_COUNT >= 1
    PUMP1_init();
    #elif   RBCTL_PUMPS_COUNT >= 2
    PUMP2_init();
    #elif   RBCTL_PUMPS_COUNT >= 3
    PUMP3_init();
    #elif   RBCTL_PUMPS_COUNT >= 4
    PUMP4_init();
    #endif
}

#endif // UNIT_TEST
