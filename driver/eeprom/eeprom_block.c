#include "eeprom_block.h"
#include "eeprom_hardware.h"
#include "eeprom_position.h"
#include "eeprom_prevent_overwrite.h"
#include "eeprom_get_occurance.h"

//TODO change
uint8_t const EEPROM_BLOCK_SIZE = 16;
uint8_t const EEPROM_BLOCK_DATA_SIZE = 14;

// Block operations

// Put user data in eeprom block
struct block eeprom_data_to_block(void* data, uint8_t data_size){
    // buffer to construct a block in
    struct block res = {0};
    
    // put data in block
    for(uint8_t n = 0; n < data_size && n < (sizeof(struct block) - sizeof(struct block_head)); ++n){
        res.data[n] = ((uint8_t*)data)[n];
    }
    
    // created block
    return res;
}

// Get user data from eeprom block
void eeprom_block_to_data(struct block* in_block, void* res_data, uint8_t res_data_size){
    // get data from block
    for(uint8_t n = 0; n < res_data_size && n < (sizeof(struct block) - sizeof(struct block_head)); ++n){
        ((uint8_t*)res_data)[n] = in_block->data[n];
    }
}

// eeprom access

/* get a specific block data_block from eeprom
 * 
 * @return: 0 fail:     block not found
 *          1 success:  block sucessfully recovered
 */
bool eeprom_get_block_by_identifier(struct eeprom_hardware* eeprom_, struct data_identifier data, struct block* data_block) {
    eeprom_pointer_t block_ptr = eeprom_get_occurance(eeprom_, eeprom_->current.read_position, data, true, eeprom_search_order_latest_first);

    // TODO block does not exist
    if (block_ptr == 0xFFFF) return 0;

    eeprom_->eeprom_wait_read_block(&data_block->data, block_ptr + sizeof(struct block_head),(sizeof(struct block) - sizeof(struct block_head)));

    // success
    return 1;
}

void eeprom_write_block_by_identifier(struct eeprom_hardware* eeprom_, struct block* data_block, struct data_identifier data, bool could_be_overwritten) {
    // make sure to not overwrite fresh data
    while (eeprom_prevent_data_overwrite(eeprom_, data));

    // prepare block head
    data_block->head.overwritable  = could_be_overwritten;
    data_block->head.sequence_id   = data.sequence_id;
    data_block->head.data_type     = data.type;
    data_block->head.sentinel      = eeprom_->current.sentinel_write_value;

    eeprom_write_head(eeprom_, eeprom_->current.write_position, &data_block->head);

    eeprom_->eeprom_wait_update_block((uint8_t*)data_block->data, eeprom_->current.write_position + sizeof(struct block_head), EEPROM_BLOCK_SIZE - sizeof(struct block_head));

    eeprom_increment_current_position(eeprom_);
}

