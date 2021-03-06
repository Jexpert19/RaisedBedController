/* 
 * File:   Log_codes.h
 * Author: Jannis Diekmann
 *
 * Created on 6. Februar 2021, 14:16
 */

#ifndef LOG_CODES_H
#define	LOG_CODES_H

#ifdef	__cplusplus
extern "C" {
#endif

// All possible log events:
// Max number of elements limited by Log_entry in "Log.c"    
// Changes must be made in "Log_codes.c" to !!!
    
enum Log_codes{
    Log_code_system_boot,
    Log_code_timetable_entry_added,
    Log_code_timetable_entry_deleted
};

// String names of Log_codes
extern const char* Log_codeStrings[];
        

#ifdef	__cplusplus
}
#endif

#endif	/* LOG_CODES_H */

