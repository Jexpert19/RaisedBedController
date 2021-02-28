#include "Log_commands.h"
#include "../../driver/uart/uart.h"
#include "../../driver/eeprom/eeprom.h"
#include "../../driver/eeprom/eeprom_get_occurance.h"
#include "Log_entry.h"
#include <stdlib.h>

void Log_uart_print_complete_log(void){
    struct Log_entry entry = {0};
    eeprom_pointer_t current_entry_pos = eeprom_external.current.write_position;
    for(size_t n = 0; n < eeprom_external.eeprom_size; ++n){
        current_entry_pos = eeprom_get_occurance(&eeprom_external, current_entry_pos, (struct data_identifier){eeprom_data_type_Log_entry, 0}, false, eeprom_search_order_oldest_first);
        //eeprom_external.eeprom_wait_read_block(&entry, current_entry_pos, sizeof(struct Log_entry));
        //if()
        //read without head
        // continue with data type empty
        uart0_put_data(&entry, sizeof(Log_entry));
    }
    
    
}