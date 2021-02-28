#include "eeprom_block_head.h"
#include "eeprom_hardware.h"
#include "eeprom_pointer.h"


struct block_head eeprom_get_head(struct eeprom_hardware* eeprom_, eeprom_pointer_t ptr){
    struct block_head head = {0};
    eeprom_->eeprom_wait_read_block(&head, ptr, sizeof(struct block_head));
    return head;
}

void eeprom_write_head(struct eeprom_hardware* eeprom_, eeprom_pointer_t ptr, struct block_head* head){
    eeprom_->eeprom_wait_update_block(head, ptr, sizeof(struct block_head));
}


bool eeprom_block_head_check(struct block_head head, struct data_identifier data, bool ignore_deleted_data){
    // desired data type?
    if (head.data_type != data.type){
        return false;
    }   
    // desired sequence id?
    if (head.sequence_id != data.sequence_id){
        return false;
    }
    // deleted block?
    if(ignore_deleted_data && head.overwritable){
        return false;
    }
    
    // head matches the specification
    return true;
}
