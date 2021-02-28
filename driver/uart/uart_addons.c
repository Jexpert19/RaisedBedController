#include "uart_addons.h"
#include <stdint.h>

void uart0_put_data(void* data, size_t size){
    for(size_t n = 0; n < size; ++n){
        uart0_putc(*(uint8_t*)(data + n));
    }
}
