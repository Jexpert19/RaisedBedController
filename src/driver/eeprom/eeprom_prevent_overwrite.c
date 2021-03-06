#include "eeprom_prevent_overwrite.h"
#include "eeprom_position.h"
#include "eeprom_block_head.h"
#include "eeprom_get_occurance.h"

// return 0 -> save to write
// return 1 -> call this function again
bool eeprom_prevent_data_overwrite(struct eeprom_hardware* eeprom_, struct data_identifier data) {
    
    eeprom_pointer_t current_write_pos = eeprom_->current.write_position;

    struct block_head head = eeprom_get_head(eeprom_, current_write_pos);

    // fresh eeprom or a block that could be overwritten
    if (head.overwritable) return 0;

    // find latest occurance of the desired data_type and sequence_id
    eeprom_pointer_t latest_occurance = eeprom_get_occurance(eeprom_, eeprom_->current.read_position, (struct data_identifier){head.data_type, head.sequence_id}, false, eeprom_search_order_latest_first);

    // check if data is last of its kind
    if (latest_occurance == current_write_pos) {
        // invert sentinel
        head.sentinel ^= 1;

        // write block head to eeprom
        eeprom_write_head(eeprom_, current_write_pos, &head);

        eeprom_increment_current_position(eeprom_);
        
        // data block updated
        // call this function again to check next writing position
        return 1;
    }

    // a later save of the specific data type is already there
    // so it's save to overwrite the old one at current write position
    return 0;
}
