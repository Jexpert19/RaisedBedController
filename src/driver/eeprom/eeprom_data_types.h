/*
 * File:   eeprom_data_types.h
 * Author: Jannis Diekmann
 *
 * Created on 24. Januar 2021, 10:46
 */

#ifndef EEPROM_TYPES_H
#define	EEPROM_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    

// Enumeration of all data types you want to save in eeprom
// Sizeof(data_type) must be defined in eeprom_types.c
enum eeprom_data_type{
    eeprom_data_type_Log_entry,
    eeprom_data_type_timetable_entry,
    eeprom_data_type_empty = 0x3F
};

    
uint8_t eeprom_get_data_type_size(enum eeprom_data_type data_type);



#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_TYPES_H */