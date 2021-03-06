/* 
 * File:   eeprom_block_head.h
 * Author: Jannis Diekmann
 *
 * Created on 7. Februar 2021, 13:33
 */

#ifndef EEPROM_BLOCK_HEAD_H
#define	EEPROM_BLOCK_HEAD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>   
#include "eeprom_data_types.h"
#include "eeprom_pointer.h"
#include "eeprom_hardware.h"

    
struct data_identifier{
    // Type of data in this block defined at "eeprom_data_types.h"
    uint8_t type :6;

    // Used to get an array like behavior
    // or store data bigger than block.data
    uint8_t sequence_id :5;
};

struct block_head{
    // Flag to find current reading pos.
    bool sentinel :1;

    // Indicates that this block can be overwritten
    bool overwritable :1;

    //from struct data_identifier
    uint8_t data_type :6;
    uint8_t sequence_id :5;
   
    //TODO ensuring eeprom data is valid
    uint8_t checksum :3;
};

struct block_head eeprom_get_head(struct eeprom_hardware* eeprom_, eeprom_pointer_t ptr);
void eeprom_write_head(struct eeprom_hardware* eeprom_, eeprom_pointer_t ptr, struct block_head* head);

bool eeprom_block_head_check(struct block_head head, struct data_identifier data, bool ignore_deleted_data);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_BLOCK_HEAD_H */

