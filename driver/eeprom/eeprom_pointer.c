#include "eeprom_pointer.h"
#include "eeprom_block.h"
#include "eeprom_hardware.h"


eeprom_pointer_t eeprom_increment_ptr_by_block(eeprom_pointer_t eeprom_ptr, uint16_t eeprom_size){
    return eeprom_increment_ptr_by_blocks(eeprom_ptr, 1, eeprom_size);
}

eeprom_pointer_t eeprom_decrement_ptr_by_block(eeprom_pointer_t eeprom_ptr, uint16_t eeprom_size){
    return eeprom_decrement_ptr_by_blocks(eeprom_ptr, 1, eeprom_size);
}

eeprom_pointer_t eeprom_increment_ptr_by_blocks(eeprom_pointer_t eeprom_ptr, uint16_t n_blocks, uint16_t eeprom_size){
    eeprom_ptr += (n_blocks * EEPROM_BLOCK_SIZE);
    
    // Overflow
    if(eeprom_ptr >= eeprom_size){
        eeprom_ptr -= eeprom_size;
    }
    
    return eeprom_ptr;
}

eeprom_pointer_t eeprom_decrement_ptr_by_blocks(eeprom_pointer_t eeprom_ptr, uint16_t n_blocks, uint16_t eeprom_size){
    eeprom_pointer_t reminder = eeprom_ptr;
    eeprom_ptr -= (n_blocks * EEPROM_BLOCK_SIZE);
    
    // Underflow correction
    if(eeprom_ptr > reminder){
        eeprom_ptr += eeprom_size;
    }
    
    return eeprom_ptr;
}