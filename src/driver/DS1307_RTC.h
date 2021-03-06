/*
 * DS1307_RTC.h
 *
 * Created: 17.05.2020 15:40:58
 *  Author: Jannis Diekmann
 */ 


#ifndef DS1307_RTC_H_
#define DS1307_RTC_H_

#ifndef UNIT_TEST

#include <stdint.h>
#include <time.h>

#define DS1307_MIN_YEAR 2020


void DS1307_set_time(const struct tm* newTime);

struct tm DS1307_read_raw_time();

time_t DS1307_read_time_sec();


void DS1307_write_ram(uint8_t address,			//ram address 0 to 55 (ram offset already considered)
					  const void* data,			//data to write
					  uint8_t size_of_data		//number of bytes to write 1 to 56
					  );

void DS1307_read_ram(uint8_t address,			//ram address 0 to 55 (ram offset already considered)
					 void* data,				//data from ram
					 uint8_t size_of_data		//number of bytes to read 1 to 56
					 );
					 
#endif // UNIT_TEST

#endif /* DS1307_RTC_H_ */
