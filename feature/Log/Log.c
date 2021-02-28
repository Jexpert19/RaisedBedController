/*
 * Log.c
 *
 * Created: 02.06.2020 10:12:27
 *  Author: Jannis Diekmann
 */ 

#include "Log.h"
#include "../../driver/uart/uart.h"
#include "../../driver/eeprom/eeprom.h"
#include <time.h>


void Log_init(){
	Log_storeEntry(Log_tag_info, Log_code_system_boot, NULL);
}


void Log_storeEntry(enum Log_tags tag, enum Log_codes event_code, struct Log_data* additional_data){
    // Buffer to construct a log entry in
    struct Log_entry entry = {0};
    
    // Make timestamp and copy entry data into buffer
    entry.eventTimeStamp    = time(NULL);
    entry.tag               = tag;
    entry.event_code        = event_code;
    
    // If available copy additional data
    if(additional_data != NULL) entry.additional_data   = *additional_data;
    
    eeprom_update_data_by_identifier(&eeprom_external, &entry, (struct data_identifier){eeprom_data_type_Log_entry, 0});
}



 
