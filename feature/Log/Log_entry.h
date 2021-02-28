/* 
 * File:   Log_entry.h
 * Author: Jannis Diekmann
 *
 * Created on 10. Februar 2021, 22:11
 */

#ifndef LOG_ENTRY_H
#define	LOG_ENTRY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdint.h>
    
    
struct Log_data{
    uint8_t data[8];
};

struct Log_entry{
	// Event time stamp
	time_t eventTimeStamp;
    
    // Tag so categorize the entries
    uint8_t tag         :3;
    
    // Code that encodes what happened
    uint8_t event_code  :6;
    
    // Additional event data
	struct Log_data additional_data;
};


#ifdef	__cplusplus
}
#endif

#endif	/* LOG_ENTRY_H */

