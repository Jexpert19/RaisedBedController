/*
 * File:   eeprom_block.h
 * Author: Jannis Diekmann
 *
 * Created on 24. Januar 2021, 10:46
 */

#ifndef INTERNAL_EEPROM_BLOCK_H
#define	INTERNAL_EEPROM_BLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "eeprom_data_types.h"
#include "eeprom_block_head.h"
#include "eeprom_hardware.h"
#include <stdint.h>
#include <stdbool.h>

    
// EEPROM data is stored in blocks
// each with a block_head and a data section
    
// TODO change
extern const uint8_t EEPROM_BLOCK_SIZE;
extern const uint8_t EEPROM_BLOCK_DATA_SIZE;

    
// EEPROM data block
struct block{
    // Head
    struct block_head head;

    // User data
    uint8_t data[14];
    //TODO change
};

struct block eeprom_data_to_block(void* data, uint8_t data_size);
void eeprom_block_to_data(struct block* in_block, void* res_data, uint8_t res_data_size);

bool eeprom_get_block_by_identifier(struct eeprom_hardware* eeprom_, struct data_identifier data, struct block* data_block);
void eeprom_write_block_by_identifier(struct eeprom_hardware* eeprom_, struct block* data_block, struct data_identifier data, bool could_be_overwritten);


#ifdef	__cplusplus
}
#endif

#endif	/* INTERNAL_EEPROM_BLOCK_H */
