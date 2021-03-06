/* 
 * File:   eeprom_uart_comands.h
 * Author: Jannis Diekmann
 *
 * Created on 17. Februar 2021, 18:22
 */

#ifndef EEPROM_UART_COMANDS_H
#define	EEPROM_UART_COMANDS_H

#ifndef UNIT_TEST

#ifdef	__cplusplus
extern "C" {
#endif

#include "eeprom_hardware.h"
    

void eeprom_print_content(enum eeprom_types eeprom_type);


#ifdef	__cplusplus
}
#endif

#endif // UNIT_TEST

#endif	/* EEPROM_UART_COMANDS_H */

