/* 
 * File:   eeprom_prevent_overwrite.h
 * Author: Jannis Diekmann
 *
 * Created on 14. Februar 2021, 12:42
 */

#ifndef EEPROM_PREVENT_OVERWRITE_H
#define	EEPROM_PREVENT_OVERWRITE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "eeprom_block_head.h"
#include "eeprom_hardware.h"
    
bool eeprom_prevent_data_overwrite(struct eeprom_hardware* eeprom_, struct data_identifier data);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_PREVENT_OVERWRITE_H */

