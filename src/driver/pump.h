/*
 * pump.h
 *
 * Created: 17.05.2020 21:00:03
 *  Author: Jannis Diekmann
 */ 

#ifndef PUMP_H_
#define PUMP_H_

#ifndef UNIT_TEST

#include <time.h>

#include "IO/RBCTL_hardware.h"
#include "../utility/macro.h"


#define mk_unit_function_decl(name) void name ## _turn_on();    \
                                    void name ## _turn_off();   \
                                    void name ## _init();

#define mk_unit(name)           {name ## _turn_on, name ## _turn_off, TOSTR(name)}


#if     RBCTL_PUMPS_COUNT >= 1
mk_unit_function_decl(PUMP1)
#elif   RBCTL_PUMPS_COUNT >= 2
mk_unit_function_decl(PUMP2)
#elif   RBCTL_PUMPS_COUNT >= 3
mk_unit_function_decl(PUMP3)
#elif   RBCTL_PUMPS_COUNT >= 4
mk_unit_function_decl(PUMP4)
#endif


extern struct unit pumps[];


void pump_init(void);
        
//double operating_hours???
//time_t operating time ???

#endif // UNIT_TEST

#endif /* PUMP_H_ */
