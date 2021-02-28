/* 
 * File:   configuration_bits.h
 * Author: Jannis Diekmann
 *
 * Created on 8. November 2020, 11:43
 */

#ifndef CONFIGURATION_BITS_H
#define	CONFIGURATION_BITS_H

#ifdef	__cplusplus
extern "C" {
#endif

// ATmega328P Configuration Bit Settings

// 'C' source line config statements

#include <avr/io.h>

FUSES = {
	.low      = 0xFF, // LOW {SUT_CKSEL=EXTXOSC_8MHZ_XX_16KCK_14CK_65MS, CKOUT=CLEAR, CKDIV8=CLEAR}
	.high     = 0xDE, // HIGH {BOOTRST=SET, BOOTSZ=256W_3F00, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, DWEN=CLEAR, RSTDISBL=CLEAR}
	.extended = 0xFD, // EXTENDED {BODLEVEL=2V7}
};

LOCKBITS = {
                0xFF, // LOCKBIT {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}
};


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGURATION_BITS_H */

