/* 
 * File:   MOCK_eeprom_hardware_mapping.h
 * Author: Jannis Diekmann
 *
 * Created on 15. Februar 2021, 15:37
 */

#ifndef MOCK_EEPROM_HARDWARE_MAPPING_H
#define	MOCK_EEPROM_HARDWARE_MAPPING_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#ifdef UNIT_TEST

#include "../../../driver/eeprom/eeprom_hardware.h"
#include <stdint.h>
    
extern struct eeprom_hardware eeprom_unittest;

void test_init(void);

#endif


#ifdef	__cplusplus
}
#endif

#endif	/* MOCK_EEPROM_HARDWARE_MAPPING_H */

