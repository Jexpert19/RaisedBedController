/* 
 * File:   eeprom_position.h
 * Author: Jannis Diekmann
 *
 * Created on 8. Februar 2021, 18:28
 */

#ifndef EEPROM_POSITION_H
#define	EEPROM_POSITION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "eeprom_hardware.h"
    

void eeprom_initalize_position_from_eeprom(struct eeprom_hardware* eeprom_);

void eeprom_increment_current_position(struct eeprom_hardware* eeprom_);
    
struct position eeprom_get_position_and_sentinel_value(struct eeprom_hardware* eeprom_);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_POSITION_H */