/* 
 * File:   eeprom_pointer.h
 * Author: Jannis Diekmann
 *
 * Created on 11. Februar 2021, 21:00
 */

#ifndef EEPROM_POINTER_H
#define	EEPROM_POINTER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>    
    
typedef uint16_t eeprom_pointer_t;
    
eeprom_pointer_t eeprom_increment_ptr_by_block(eeprom_pointer_t eeprom_ptr, uint16_t eeprom_size);

eeprom_pointer_t eeprom_decrement_ptr_by_block(eeprom_pointer_t eeprom_ptr, uint16_t eeprom_size);

eeprom_pointer_t eeprom_increment_ptr_by_blocks(eeprom_pointer_t eeprom_ptr, uint16_t n_blocks, uint16_t eeprom_size);

eeprom_pointer_t eeprom_decrement_ptr_by_blocks(eeprom_pointer_t eeprom_ptr, uint16_t n_blocks, uint16_t eeprom_size);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_POINTER_H */

