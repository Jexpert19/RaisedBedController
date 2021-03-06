#ifndef UNIT_TEST

#include <stdint.h>
#include "eeprom_hardware_mapping.h"
#include <avr/eeprom.h>
#include "AT24C32_EEPROM.h"
#include "eeprom_block_head.h"

// Internal:

void internal_read_block(void* data_out, uint16_t address, size_t size){
    eeprom_busy_wait();
    eeprom_read_block(data_out, (uint16_t*)address, size);
}

void internal_write_block(const void* data_in, uint16_t address, size_t size){
    eeprom_busy_wait();
    eeprom_update_block(data_in, (uint16_t*)address, size);
}

// External:

void external_read_block(void* data_out, uint16_t address, size_t size){
    AT24C32_read(address, data_out, (uint16_t)size);
}

void external_write_block(const void* data_in, uint16_t address, size_t size)
{
    AT24C32_write(address, data_in, (uint16_t)size);
}


struct eeprom_hardware eeprom_internal = {
    .eeprom_size = 1024,
    .eeprom_wait_read_block = internal_read_block,
    .eeprom_wait_update_block = internal_write_block,
    .current = {0}
};

struct eeprom_hardware eeprom_external = {
    .eeprom_size = 4096,
    .eeprom_wait_read_block = external_read_block,
    .eeprom_wait_update_block = external_write_block,
    .current = {0}
};

#endif // UNIT_TEST
