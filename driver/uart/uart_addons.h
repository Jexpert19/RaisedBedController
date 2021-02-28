/* 
 * File:   uart_addons.h
 * Author: Jannis Diekmann
 *
 * Created on 22. Februar 2021, 17:56
 */

#ifndef UART_ADDONS_H
#define	UART_ADDONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "uart.h"
#include <stdlib.h>

void uart0_put_data(void* data, size_t size);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_ADDONS_H */

