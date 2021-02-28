/*
 * Commands.h
 *
 * Created: 22.05.2020 22:05:38
 *  Author: Jannis Diekmann
 */ 


#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdint.h>

#include "../driver/eeprom/AT24C32_EEPROM.h"

#define MAX_ARG_LENGHT 32


struct command{
	char symbol;
	const char description[40];
	void (*function_ptr)(const char*);
};

//command implementation

void com_help();

void com_set_time(const char* arg);

void com_print_time(const char* arg);

/*void com_write_eeprom(const char* arg);

void com_read_eeprom(const char* arg);*/

void com_show_free(const char* arg);

void com_print_mem_free(const char* arg);

void com_read_log(const char* arg);

void com_write_log(const char* arg);

void com_delete_log(const char* arg);

void com_read_DS1307_RAM(const char* arg);

void com_toggle_led(const char* arg);

void com_adc0(const char* arg);

uint8_t commands_count;


#endif /* COMMANDS_H_ */