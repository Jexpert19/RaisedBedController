#include "eeprom_data_types.h"

// Files to find the data types in
#include "../../feature/Log/Log.h"                    // struct Log_entry
#include "../../feature/timetable/timetable.h"        // struct timetable_entry



// Size of all data types
// Must fit the order of the enum
// Must be less or equal BLOCK_DATA_SIZE from eeprom_block.h
const uint8_t eeprom_data_type_size[] = {
    sizeof(struct Log_entry),
    sizeof(struct timetable_entry)
};

uint8_t eeprom_get_data_type_size(enum eeprom_data_type data_type){
    return eeprom_data_type_size[data_type];
}

