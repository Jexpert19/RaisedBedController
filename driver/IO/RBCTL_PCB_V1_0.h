/* 
 * File:   RBCTL_PCB_V1_0.h
 * Author: Jannis Diekmann
 *
 * Created on 16. Januar 2021, 15:21
 */

#ifndef RBCTL_PCB_V1_0_H
#define	RBCTL_PCB_V1_0_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "IOMAP_ArduinoProMini.h"
#include "../ADC.h"

//I/O association
#define IO_FILL_LEVEL_SENSOR                	PD2_
#define IO_PUMP1                             	PD3_
#define IO_HMI_BUTTON                           PD4_
#define IO_IO0                              	PD5_
#define IO_IO1                              	PD6_
#define IO_HMI_ENCODER_A                        PD7_
#define IO_HMI_ENCODER_B                        PB0_
#define IO_IO2                              	PB1_
#define IO_IO3                              	PB2_

// Analog capable pins:
#define IO_A0                                   PC0_
#define IO_A1                                   PC1_
#define IO_A2                                   PC2_
#define IO_A3                                   PC3_
    
// Analog only pins:
#define IO_A6                                   A6_
#define IO_A7                                   A7_

    
void RBCTL_PCB_V1_0_init();
    

#ifdef	__cplusplus
}
#endif

#endif	/* RBCTL_PCB_V1_0_H */

