/*
 * Commands.c
 *
 * Created: 22.05.2020 22:05:55
 *  Author: Jannis Diekmann
 */
 
#ifndef UNIT_TEST

#include "Commands.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "../driver/DS1307_RTC.h"
#include "../driver/uart/uart.h"

#include "timetable/timetable_commands.h"

//destroy when project is finished:
#include "MemCheck.h"

const char TEXT_BLOCK_DEVIDER[] = "--------------------\n";


struct command uart_commands[] = {
    {.symbol='a', .description="get system time"						, .function_ptr=com_print_time					},
    {.symbol='b', .description="set system time YYYY-MM-DD hh:mm:ss"	, .function_ptr=com_set_time					},
    {.symbol='c', .description="res"                                	, .function_ptr=com_help    					},
    {.symbol='d', .description="res"                                   	, .function_ptr=com_help        				},
    {.symbol='e', .description="res"            						, .function_ptr=com_help            			},
    {.symbol='f', .description="show minimum free ram"					, .function_ptr=com_print_mem_free				},
    {.symbol='g', .description="res"                            		, .function_ptr=com_help    					},
    {.symbol='h', .description="new timer sH:sM:sS dH:dM:dS iD iH:iM:iS", .function_ptr=com_new_timer					},
    {.symbol='i', .description="toggle LED"                             , .function_ptr=com_toggle_led                  },
    {.symbol='j', .description="read DS1307 RAM"						, .function_ptr=com_read_DS1307_RAM				},
    {.symbol='k', .description="read A0"                           		, .function_ptr=com_adc0                        },
    {.symbol='l', .description="show timer -id"  						, .function_ptr=com_show_timer					},
    {.symbol='m', .description="delete timer -id"						, .function_ptr=com_delete_timer				},
    //should not be visible ... has to be changed ... bad design
    {.symbol='\n',.description=""                                       , .function_ptr=com_help                        }
};

uint8_t commands_count = (sizeof(uart_commands) / sizeof(uart_commands[0]));


void com_help(const char* arg){
	uart0_puts("Commands available:\n\n");
	for(int n=0; n < commands_count; ++n){
		uart0_putc(uart_commands[n].symbol);
		uart0_putc(' ');
		uart0_puts(uart_commands[n].description);
		uart0_putc('\n');
	}
	uart0_puts(TEXT_BLOCK_DEVIDER);
}

//calculate the week day (0 - 6) days since Sunday
int dayofweek(int d, int m, int y)
{
	const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

//format: YYYY-MM-DD hh:mm:ss
void com_set_time(const char* arg){
	
	//convert input
	struct tm inputTime = {0};
	if(sscanf(arg, "%u-%hhu-%hhu %hhu:%hhu:%hhu", &inputTime.tm_year,
												  &inputTime.tm_mon,
												  &inputTime.tm_mday,
												  &inputTime.tm_hour,
												  &inputTime.tm_min,
												  &inputTime.tm_sec
												  )!= 6){
		uart0_puts("Wrong input\n");
		uart0_puts(TEXT_BLOCK_DEVIDER);
		return;
}
    //calculate weekday before converting inputTime to a legal tm struct format
    inputTime.tm_wday = dayofweek(inputTime.tm_mday, inputTime.tm_mon, inputTime.tm_year);
    
	//Convert input to struct tm format
	inputTime.tm_mon -= 1;
	inputTime.tm_year -= 1900;
	
	//set time
	DS1307_set_time(&inputTime);
}

#include <time.h>

void com_print_time(const char* arg){
    time_t current_t = time(0);
	uart0_puts(ctime(&current_t));
	uart0_putc('\n');
	uart0_puts(TEXT_BLOCK_DEVIDER);
}


void com_print_mem_free(const char* arg){
	char data[5];
	itoa(get_mem_unused(), data, 10);
	uart0_puts((char*)data);
}

void com_read_DS1307_RAM(const char* arg){
	uint8_t data[56];
	
	//read data
	DS1307_read_ram(0, (uint8_t*)data, 56);
	
	//print out
	for(int n=0; n < 56; ++n){
		uart0_putc(data[n]);
	}
}

#include "../driver/IO/RBCTL_hardware.h"

void com_toggle_led(const char* arg){
	IO_TOGGLE(IO_ONBOARD_LED);
}

void com_adc0(const char* arg){
    char out[5] = {0};
    itoa(ADC_Read_Avg(IO_ANALOG(IO_A0), 10), (char*)out, 10);
    uart0_puts((char*)out);
    uart0_puts("\n");
} 

#endif // UNIT_TEST
