/*
 * DS1307_RTC.c
 *
 * Created: 17.05.2020 15:40:37
 *  Author: Jannis Diekmann
 */ 

#ifndef UNIT_TEST

#include "DS1307_RTC.h"

#include "i2cmaster.h"

//hardware definitions:

#define DS1307_ADDRESS_W (uint8_t)0b11010000
#define DS1307_ADDRESS_R (uint8_t)0b11010001

#define DS1307_RAM_OFFSET 0x08
#define DS1307_RAM_SIZE 56

#define DS1307_CLK_EN_BIT 7
#define DS1307_12_24_HOUR_SEL_BIT 6


uint8_t dec_to_bcd(uint8_t val) {
	return (((val / 10) << 4)) + (val - (val / 10)*10);
}

uint8_t bcd_to_dec(uint8_t val) {
	return ((val >> 4) * 10 + (val & 0x0F));
}


void DS1307_set_time(const struct tm* newTime){
	
	//start communication
	i2c_start_wait(DS1307_ADDRESS_W);
	
	//set word address to first register (0)
	i2c_write(0x00);
	
	//set second and date and enable the oscillator
	i2c_write(dec_to_bcd(newTime->tm_sec) & ~(1 << DS1307_CLK_EN_BIT));
	
	i2c_write(dec_to_bcd(newTime->tm_min));
	
	//set hour and enable 24 hour mode
	i2c_write(dec_to_bcd(newTime->tm_hour) & ~(1 << DS1307_12_24_HOUR_SEL_BIT));
	
	//below 10 so no conversation necessary
	i2c_write(newTime->tm_wday + 1);
	
	//set month day, month and year
	i2c_write(dec_to_bcd(newTime->tm_mday));
	i2c_write(dec_to_bcd(newTime->tm_mon + 1));
	i2c_write(dec_to_bcd(newTime->tm_year - 120));
	
	//stop communication
	i2c_stop();
}

struct tm DS1307_read_raw_time(){
	struct tm res = {0};
	i2c_start_wait(DS1307_ADDRESS_W);
	i2c_write(0x00);
	i2c_rep_start(DS1307_ADDRESS_R);
	
	res.tm_sec   = bcd_to_dec(i2c_readAck() & ~(1 << DS1307_CLK_EN_BIT));
	res.tm_min   = bcd_to_dec(i2c_readAck());
	res.tm_hour  = bcd_to_dec(i2c_readAck() & ~(1 << DS1307_12_24_HOUR_SEL_BIT));
	
	//below 10 so no conversation necessary
	res.tm_wday  = i2c_readAck() - 1;												//Weekdays from 0 to 6
	
	res.tm_mday  = bcd_to_dec(i2c_readAck());
	res.tm_mon   = bcd_to_dec(i2c_readAck()) - 1;									//Months from 0 to 11
	res.tm_year  = bcd_to_dec(i2c_readNak()) + 120;									//Years since 1900
																					//Daylight saving ???
	i2c_stop();
	return res;
}


time_t DS1307_read_time_sec(){
	struct tm res = DS1307_read_raw_time();
	return mktime(&res);
}




//Ram access functions:


//Write RAM:

void DS1307_write_ram(uint8_t address,						//ram address 0 to 55 (ram offset already considered)
					  const void* data,						//data to write
					  uint8_t size_of_data					//number of bytes to write 1 to 56
					 ){ 
	if(address + size_of_data > DS1307_RAM_SIZE) return;	//prevent overflow of address pointer and the followed crash of the clock
	
	i2c_start_wait(DS1307_ADDRESS_W);
	i2c_write(DS1307_RAM_OFFSET + address);					//set DS1307 pointer
	
	while(size_of_data){
		i2c_write(*(uint8_t*)data);
		++data;
		--size_of_data;
	}
	
	i2c_stop();
}

//Read RAM:

void DS1307_read_ram(uint8_t address,						//ram address 0 to 55 (ram offset already considered)
					 void* data,							//data in ram
					 uint8_t size_of_data					//number of bytes to read 1 to 56
				    ){	 
	if(address + size_of_data > DS1307_RAM_SIZE) return;	//prevent overflow of address pointer and so corrupted data
	 
	 i2c_start_wait(DS1307_ADDRESS_W);
	 i2c_write(DS1307_RAM_OFFSET + address);				//set DS1307 pointer
	 i2c_rep_start(DS1307_ADDRESS_R);
	 
	 while(size_of_data -1){
		 *(uint8_t*)data = i2c_readAck();
		 ++data;
		 --size_of_data;
	 }
	 
	 *(uint8_t*)data = i2c_readNak();
	 
	i2c_stop();
}

#endif // UNIT_TEST
