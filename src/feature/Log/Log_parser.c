#include "Log_parser.h"
#include "Log_codes.h"
#include "Log_tags.h"
#include <stdbool.h>
#include <string.h>

// timetable.h
extern void timetable_log_data_parse(struct Log_data* data, char* res);


void Log_parse_additional_data(struct Log_entry* entry, char* res){
    // Put additional data in parenthesis
    strcat(res, " (");
    
    // No additional data
    bool noAdditionalData = false;
    
    // Select functions to process additional data
    switch(entry->event_code){
        
        // timetable.h:
        case Log_code_timetable_entry_added:
        case Log_code_timetable_entry_deleted:
            timetable_log_data_parse(&entry->additional_data, res);
            break;
            
        // No data to parse
        default:
            noAdditionalData = true;
            break;
    }
    
    // Remove parenthesis if there is no additional data by shorten the string
    if(noAdditionalData)    res[strlen(res) - 2] = '\0';
    else                    strcat(res, ")");
    
    // Line feed
    strcat(res, "\n");
}


void Log_parse_entry(struct Log_entry* entry, char* res){
    // Timestamp
    strcat(res, ctime(&entry->eventTimeStamp));
    strcat(res, " [");
    
    // Tag
	strcat(res, Log_tagStrings[entry->tag]);
    strcat(res, "]: ");
    
    // Event
    strcat(res, Log_codeStrings[entry->event_code]);
        
    // Additional data
    Log_parse_additional_data(entry, res);
}
