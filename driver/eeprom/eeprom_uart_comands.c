#include "eeprom_uart_comands.h"
#include "eeprom_block.h"
#include "eeprom_hal.h"
#include "../uart/uart.h"
#include <stdlib.h>


void eeprom_print_content(enum eeprom_types eeprom_type){
    for(uint16_t n = 0; n < eeprom_interface[eeprom_type].eeprom_size; n += sizeof(buffer)){
        uint8_t buffer[BLOCK_SIZE];
        eeprom_interface[eeprom_type].eeprom_wait_read_block(&buffer , n, sizeof(buffer));
        uart0_put_data(&buffer, sizeof(buffer));
    }
}