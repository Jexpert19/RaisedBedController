#include "eeprom_get_occurance.h"


eeprom_pointer_t eeprom_get_occurance(struct eeprom_hardware* eeprom_, eeprom_pointer_t search_start, struct data_identifier data, bool ignore_attribute_overwritable, enum eeprom_search_order search_order){
    eeprom_pointer_t position = search_start;
    struct block_head head;
    do{
        head = eeprom_get_head(eeprom_, position);
        
        // desired block?
        if(eeprom_block_head_check(head, data, ignore_attribute_overwritable)){
            return position;
        }
        
        if(search_order == eeprom_search_order_latest_first){
            // decrement to get from new to -> old blocks
            position = eeprom_decrement_ptr_by_block(position, eeprom_->eeprom_size);
        }
        if(search_order == eeprom_search_order_oldest_first){
            // increment to get from new old -> new blocks
            position = eeprom_increment_ptr_by_block(position, eeprom_->eeprom_size);
        }
        
    }while(
           ((search_order == eeprom_search_order_latest_first) && (position != eeprom_->current.read_position)) || 
           ((search_order == eeprom_search_order_oldest_first) && (position != eeprom_->current.write_position))
          );
    
    // TODO not found
    return 0xFFFF;
}