/* 
 * File:   eeprom_get_occurance.h
 * Author: Jannis Diekmann
 *
 * Created on 21. Februar 2021, 12:13
 */

#ifndef EEPROM_GET_OCCURANCE_H
#define	EEPROM_GET_OCCURANCE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "eeprom_pointer.h"
#include "eeprom_data_types.h"
#include "eeprom_block_head.h"
    
enum eeprom_search_order{
    eeprom_search_order_latest_first,
    eeprom_search_order_oldest_first
};
    
eeprom_pointer_t eeprom_get_occurance(struct eeprom_hardware* eeprom_, eeprom_pointer_t search_start, struct data_identifier data, bool ignore_attribute_overwritable, enum eeprom_search_order search_order);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_GET_OCCURANCE_H */

