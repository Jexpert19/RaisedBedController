#include "timetable_commands.h"
#include "timetable.h"
#include <stdio.h>
#include "../../driver/uart/uart.h"

void com_new_timer(const char* arg){
    int8_t start_h, start_m, start_s,
           duration_h, duration_m, duration_s, 
           interval_d, interval_h, interval_m, interval_s;
    if(sscanf(arg, "%hhi:%hhi:%hhi %hhi:%hhi:%hhi %hhi %hhi:%hhi:%hhi", &start_h, &start_m, &start_s,
                                                                        &duration_h, &duration_m, &duration_s,
                                                                        &interval_d, &interval_h, &interval_m, &interval_s) != 10){
        uart0_puts("check argument\n");
        return;
    }
  
    time_t start_t = 0;
    
    if(start_h || start_m || start_s){
        //current time
        struct tm current_tm = {0};
        time_t current_t = time(0);
        gmtime_r(&current_t, &current_tm);
        
        //buffer to store
        struct tm start_tm = {0};
        start_tm.tm_hour = start_h;
        start_tm.tm_min = start_m;
        start_tm.tm_sec = start_s;
        start_tm.tm_year = current_tm.tm_year;
        start_tm.tm_mon = current_tm.tm_mon;
        start_tm.tm_mday = current_tm.tm_mday;
        start_t = mktime(&start_tm);
    }
    
    time_t duration_t = (time_t)duration_s + (60 * ((time_t)duration_m + (60 * (time_t)duration_h)));
    
    time_t interval_t = (time_t)interval_s + (60 * ((time_t)interval_m + (60 * ((time_t)interval_h + (24 * (time_t)interval_d)))));
    
    if(timetable_add(start_t, duration_t, interval_t, 0))
        uart0_puts("success\n");
    else
        uart0_puts("failed\n");
}

void print_time_t(time_t* timer){
    struct tm timer_tm;
    gmtime_r(timer, &timer_tm);
    
    char res_str[5];
    
    itoa((int)timer_tm.tm_hour, (char*)res_str, 10); 
    uart0_puts(res_str);
    uart0_putc(':');
    
    itoa((int)timer_tm.tm_min, (char*)res_str, 10); 
    uart0_puts(res_str);
    uart0_putc(':');
    
    itoa((int)timer_tm.tm_sec, (char*)res_str, 10); 
    uart0_puts(res_str);
}

void com_show_timer(const char* arg){
    uint8_t id;
    sscanf(arg, "%hhu", &id);
    struct timetable_entry* res;
    res = timetable_get(id);
   
    //not valid?
    if(res == 0) {
        uart0_puts("failed\n");
        return;
    }
    
    //next event
    struct tm timer_tm;
    gmtime_r(&res->next_event, &timer_tm);
    
    //next event
    uart0_puts("next_event: ");
    uart0_puts(ctime(&res->next_event));
    uart0_putc('\n');
    
    //duration
    uart0_puts("duration: ");
    print_time_t(&res->duration_of_activation);
    uart0_puts("\n");
    
    uart0_puts("interval: ");
    print_time_t(&res->interval);
    uart0_puts("\n");
}

void com_delete_timer(const char* arg){
    uint8_t id;
    sscanf(arg, "%hhu", &id);
    if(timetable_delete(id))
        uart0_puts("deleted\n");
    else
        uart0_puts("failed\n");
}

