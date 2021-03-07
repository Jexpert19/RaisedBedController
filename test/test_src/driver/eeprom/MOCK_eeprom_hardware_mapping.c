#include "MOCK_eeprom_hardware_mapping.h"
#include <stdint.h>
#include <stdlib.h>
#include "driver/eeprom/eeprom_pointer.h"

#define EEPROM_SIZE 48

uint8_t dummy_storage[EEPROM_SIZE];

void fill_array(void* arr, size_t size, uint8_t value){
    for(size_t n = 0; n < size; ++n){
        *(uint8_t*)(arr + n) = value;
    }
}

void test_init(void){
    fill_array(&dummy_storage, sizeof(dummy_storage), 0xFF);
}

void MOCK_read(const void* data_out, uint16_t address, size_t size){
    for(size_t n = 0; n < size; ++n){
        *(uint8_t*)(data_out + n) = dummy_storage[address + n];
    }
}

void MOCK_write(const void* data_in, uint16_t address, size_t size){
    for(size_t n = 0; n < size; ++n){
        dummy_storage[address + n] = *(uint8_t*)(data_in + n);
    }
}

struct eeprom_hardware eeprom_unittest = {
    .eeprom_size = EEPROM_SIZE,
    .eeprom_wait_read_block = MOCK_read,
    .eeprom_wait_update_block = MOCK_write,
	.current = {0}
};

