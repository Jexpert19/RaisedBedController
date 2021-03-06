/* 
 * File:   timetable_commands.h
 * Author: Jannis Diekmann
 *
 * Created on 17. Februar 2021, 20:45
 */

#ifndef TIMETABLE_COMMANDS_H
#define	TIMETABLE_COMMANDS_H

#ifndef UNIT_TEST

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <time.h>
    

void com_new_timer(const char* arg);

void print_time_t(time_t* timer);

void com_show_timer(const char* arg);

void com_delete_timer(const char* arg);


#ifdef	__cplusplus
}
#endif

#endif // UNIT_TEST

#endif	/* TIMETABLE_COMMANDS_H */

