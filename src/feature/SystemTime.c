/*
 * SystemTime.c
 *
 * Created: 27.07.2020 17:17:15
 *  Author: Jannis Diekmann
 */ 
 
#ifndef UNIT_TEST
 
#include "SystemTime.h"

#include <time.h>
#include <avr/interrupt.h>

#include "../driver/uart/uart.h"
#include "Parser.h"
#include "timetable/event.h"

//ISR in SystemTime
void check_events(){
    if(uart0_available()) handle_uart_input();
    timetable_events_run();
}

ISR(TIMER1_COMPA_vect, ISR_NAKED){
	system_tick();
    check_events();
	reti();
}

#endif // UNIT_TEST
