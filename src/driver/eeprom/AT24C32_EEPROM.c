/*
 * AT24C32_EEPROM.c
 *
 * Created: 18.05.2020 17:49:49
 *  Author: Jannis Diekmann
 */ 
 
#ifndef UNIT_TEST

#include "AT24C32_EEPROM.h"
#include <ctype.h>
#include "../i2cmaster.h"

//hardware definitions:

#define AT24C32_ADDRESS_W (uint8_t)  0b10100000
#define AT24C32_ADDRESS_R (uint8_t)  0b10100001

#define AT24C32_SIZE	  (uint16_t) 4096

#define AT24C32_PAGE_SIZE (uint16_t) 32
#define AT24C32_PAGE_COUNT (uint16_t) (AT24C32_SIZE / AT24C32_PAGE_SIZE)
#define AT24C32_WORD_ADDR_BIT_COUNT  (uint8_t) 5
#define AT24C32_WORD_ADDR_MASK (uint16_t) (AT24C32_PAGE_SIZE - 1)

void AT24C32_write(uint16_t address, const void* data, uint16_t data_size){
	//no data?
	if(data_size == 0) return;
	
	while(1){
		//start communication and transmit device address
		//if EEPROM is busy use ACK-polling
		i2c_start_wait(AT24C32_ADDRESS_W);
		
		//set EEPROM internal pointer
		i2c_write(address >> 8);
		i2c_write(address & 0xFF);
		
		//write until page end
		while(1)
		{	
			//write data word to EEPROM
			i2c_write(*(uint8_t*)data);
			
            //decrement "data_size" till 0
            --data_size;
            
            //stop communication and return if transfer is complete
			if(data_size == 0){
				i2c_stop();
				return;
			}
            
            //increment data pointer
            ++data;
            
            //increment address
			++address;
            
			//break after word 31 of page and let EEPROM process page
			if ((address & AT24C32_WORD_ADDR_MASK) == 0) break;
		}
        
		//stop communication and wait for EEPROM to write data
		i2c_stop();
	}
}

void AT24C32_read(uint16_t address, void* data, uint16_t data_size){
    //don't want to read?
	if(data_size == 0) return;
    
	//start communication and transmit device address
	i2c_start_wait(AT24C32_ADDRESS_W);
	
	//set EEPROM internal pointer
	i2c_write(address >> 8);
	i2c_write(address & 0xFF);
	
	//restart communication in read mode
	i2c_rep_start(AT24C32_ADDRESS_R);
	
	while(data_size > 1){
		//read data byte and acknowledge(ACK)
		*(uint8_t*)data = i2c_readAck();
		
		//decrement size marker
		--data_size;
        
		//increase data pointer
		++data;
	}
	//read and don't acknowledge(NAK)
	*(uint8_t*)data = i2c_readNak();
	
	//stop communication
	i2c_stop();
}

#endif // UNIT_TEST
