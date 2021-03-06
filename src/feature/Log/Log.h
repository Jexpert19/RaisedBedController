/*
 * Log.h
 *
 * Created: 02.06.2020 10:12:15
 *  Author: Jannis Diekmann
 */ 


#ifndef LOG_H_
#define LOG_H_

#include <stdint.h>
#include "Log_tags.h"
#include "Log_codes.h"
#include "Log_parser.h"


#define LOG_VERSION 0.1


void Log_init();

void Log_storeEntry(enum Log_tags tag, enum Log_codes event_code, struct Log_data* additional_data);

//void Log_uartPrintEntry();


#endif /* LOG_H_ */