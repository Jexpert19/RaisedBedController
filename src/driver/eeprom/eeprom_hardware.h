/* 
 * File:   eeprom_hardware.h
 * Author: Jannis Diekmann
 *
 * Created on 15. Februar 2021, 15:55
 */

#ifndef EEPROM_HARDWARE_H
#define	EEPROM_HARDWARE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "eeprom_pointer.h"
    
// With a sentinel the read/write position of an
// eeprom will be found even after power loss
struct position{
    eeprom_pointer_t read_position;
    eeprom_pointer_t write_position;
    bool sentinel_write_value;
};
    
struct eeprom_hardware{
    const size_t eeprom_size;
    void (*eeprom_wait_read_block)(void* data_out, eeprom_pointer_t address, size_t __n);
    void (*eeprom_wait_update_block)(const void* data_in, eeprom_pointer_t address, size_t __n);
    struct position current;                  
};


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_HARDWARE_H */

