#include "eeprom.h"


// the basic algorithm:
// https://sites.google.com/site/dannychouinard/Home/atmel-avr-stuff/eeprom-longevity

#include <stdlib.h>
#include "eeprom_block.h"
#include "eeprom_block_head.h"
#include "eeprom_position.h"

void eeprom_init(struct eeprom_hardware* eeprom_){
    eeprom_initalize_position_from_eeprom(eeprom_);
}


bool eeprom_get_data_by_identifier(struct eeprom_hardware* eeprom_, struct data_identifier data, void* data_out){
    struct block eblock = {0};
    
    if(!eeprom_get_block_by_identifier(eeprom_, data, &eblock)) return 0;
    
    eeprom_block_to_data(&eblock, data_out, eeprom_get_data_type_size(data.type));
    
    // Success
    return 1;
}


void eeprom_update_data_by_identifier(struct eeprom_hardware* eeprom_, void* data_in, struct data_identifier data){
    struct block eblock = {0};
    
    eblock = eeprom_data_to_block(data_in, eeprom_get_data_type_size(data.type));
    
    eeprom_write_block_by_identifier(eeprom_, &eblock, data, false);
}


void eeprom_delete_data_by_identifier(struct eeprom_hardware* eeprom_, struct data_identifier data){    
    struct block eblock = {0};
    eeprom_write_block_by_identifier(eeprom_, &eblock, data, true);
}

void eeprom_set_block_to_value(void* block, uint8_t value){
    for(uint8_t n = 0; n < EEPROM_BLOCK_SIZE; ++n){
        *((uint8_t*)block + n) = value;
    }
}

void eeprom_set_all_blocks_to_value(struct eeprom_hardware* eeprom_, const uint8_t value){
    struct block empty_block;
    eeprom_set_block_to_value(&empty_block, value);
    
    for(eeprom_pointer_t n = 0; n < eeprom_->eeprom_size; n += EEPROM_BLOCK_SIZE){
        eeprom_->eeprom_wait_update_block(&empty_block, n, EEPROM_BLOCK_SIZE);
    }
}

void eeprom_complete_format(struct eeprom_hardware* eeprom_){
    const uint8_t eeprom_factory_value = 0xFF;
    eeprom_set_all_blocks_to_value(eeprom_, eeprom_factory_value);
}


