/*
 * AT24C32_EEPROM.h
 *
 * Created: 18.05.2020 17:49:27
 *  Author: Jannis Diekmann
 */ 


#ifndef AT24C32_EEPROM_H_
#define AT24C32_EEPROM_H_

#include <stdint.h>


void AT24C32_read(uint16_t address, void* data, uint16_t data_size);

void AT24C32_write(uint16_t address, const void* data, uint16_t data_size);


#endif /* AT24C32_EEPROM_H_ */