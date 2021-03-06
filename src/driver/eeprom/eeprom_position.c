#include "eeprom_position.h"
#include "eeprom_block.h"
#include "eeprom_pointer.h"
#include "eeprom_hardware_mapping.h"
#include <stdint.h>
#include <stdbool.h>

void eeprom_initalize_position_from_eeprom(struct eeprom_hardware* eeprom_){
    eeprom_->current = eeprom_get_position_and_sentinel_value(eeprom_);
}

void eeprom_increment_current_position(struct eeprom_hardware* eeprom_){
    eeprom_pointer_t reminder = eeprom_->current.write_position;
    eeprom_->current.write_position = eeprom_increment_ptr_by_block(eeprom_->current.write_position, eeprom_->eeprom_size);
    eeprom_->current.read_position = eeprom_increment_ptr_by_block(eeprom_->current.read_position, eeprom_->eeprom_size);
            
    // Overflow
    if(reminder > eeprom_->current.write_position){
        // Continue with toggled sentinel value
        eeprom_->current.sentinel_write_value ^= true;
    }
}

struct position eeprom_get_position_and_sentinel_value(struct eeprom_hardware* eeprom_){
    // reminder for sentinel and block head
    uint16_t position_reminder = 0;
    bool sentinel_reminder = 0;
    struct block_head current_head;
    
    // get first block head that is allways on addr. 0
    current_head = eeprom_get_head(eeprom_, position_reminder);
    
    // get first sentinel
    sentinel_reminder = current_head.sentinel;
    
    // move ptr to next obj
    position_reminder = EEPROM_BLOCK_SIZE; 
    
    // scan through eeprom until sentinel change found or end of eeprom is reached
    do{
        // get head from eeprom
        current_head = eeprom_get_head(eeprom_, position_reminder);

        // sentinel change found at pos: x
        if (position_reminder != current_head.sentinel) {
            // Behind the change is write pos
            struct position position_result = {
                .write_position = position_reminder,
                .read_position = position_reminder - EEPROM_BLOCK_SIZE,
                .sentinel_write_value = sentinel_reminder
            };
            return position_result;
        }
        
        // move ptr to next obj
        position_reminder += EEPROM_BLOCK_SIZE;

        sentinel_reminder = current_head.sentinel;
    }while(position_reminder < eeprom_->eeprom_size);
    
    // No sentinel change found:
    struct position position_result = {
        .write_position = 0,
        .read_position = eeprom_->eeprom_size - EEPROM_BLOCK_SIZE,
        .sentinel_write_value = !sentinel_reminder
    };
    return position_result;
}
