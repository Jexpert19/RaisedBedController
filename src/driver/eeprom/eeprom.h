/*
 * File:   eeprom.h
 * Author: Jannis Diekmann
 *
 * Created on 8. November 2020, 14:48
 */

#ifndef INTERNAL_EEPROM_H
#define	INTERNAL_EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "eeprom_block.h"
#include "eeprom_data_types.h"
#include "eeprom_hardware.h"

#ifndef UNIT_TEST
#include "eeprom_hardware_mapping.h"
#endif
    
void eeprom_init(struct eeprom_hardware* eeprom_);

bool eeprom_get_data_by_identifier(struct eeprom_hardware* eeprom_, struct data_identifier data, void* data_out);

void eeprom_update_data_by_identifier(struct eeprom_hardware* eeprom_, void* data_in, struct data_identifier data);

void eeprom_delete_data_by_identifier(struct eeprom_hardware* eeprom_, struct data_identifier data);

void eeprom_complete_format(struct eeprom_hardware* eeprom_);


#ifdef	__cplusplus
}
#endif

#endif	/* INTERNAL_EEPROM_H */
