/*
 * RaisedBetController.cpp
 *
 * Created: 10.04.2020 16:15:25
 * Author : Jannis Diekmann
 */

#ifndef UNIT_TEST

#include "configuration_bits.h"
#include "driver/IO/RBCTL_hardware.h"
#include "driver/uart/uart.h"
#include "driver/DS1307_RTC.h"
#include "driver/i2cmaster.h"
#include "driver/pump.h"
#include "feature/Parser.h"
#include "driver/lcd/lcd.h"
#include "feature/Log/Log.h"
#include "feature/timetable/timetable.h"
#include "feature/SystemTime.h"
#include "driver/eeprom/eeprom.h"

#include <avr/io.h>
//remove later
#include <util/delay.h>
#include <avr/interrupt.h>


void system_time_init(){
    OCR1A = 62498;
    TCCR1B = (1 << 3) | (1 << 2);
    TIMSK1 = (1 << 1);
}

void handle_time(){
    set_system_time(DS1307_read_time_sec());
}

void error(){
    while(1);
}


int main(void){
    RBCTL_hardware_init();
    
	uart0_init(UART_BAUD_SELECT(19200, F_CPU));
	i2c_init();
    Log_init();
	//lcd_init(LCD_DISP_ON);
	//Log_init();
    pump_init();
    eeprom_init(&eeprom_internal);
    eeprom_init(&eeprom_external);
    handle_time();
    system_time_init();
	sei();
    if(!timetable_init())
        error();
    
	//lcd_puts("RaisedBed V0.1");

	while(1){
        asm ("nop");
	}
}

#endif // UNIT_TEST
