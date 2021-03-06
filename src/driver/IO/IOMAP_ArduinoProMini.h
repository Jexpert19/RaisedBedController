/*
 * IOMAP_ArduinoProMini.h
 *
 * Created: 09.07.2020 22:03:10
 *  Author: Jannis Diekmann
 */ 


#ifndef IOMAP_ARDUINOPROMINI_H_
#define IOMAP_ARDUINOPROMINI_H_

#ifndef UNIT_TEST

#include <avr/io.h>

#include "IO.h"


#define F_CPU 16000000


// Onboard LED
#define IO_ONBOARD_LED      PB5_

// UART
#define IO_RXD              PD0_
#define IO_TXD              PD1_

// SPI
#define IO_SCK				PB5_
#define IO_MISO			    PB4_
#define IO_MOSI			    PB3_
#define IO_SS				PB2_

// TWI (I2C)
#define IO_SCL			    PC5_
#define IO_SDA			    PC4_

// Analog
// ADCMUX values
#define A0                  0
#define A1                  1
#define A2                  2
#define A3                  3
#define A4                  4
#define A5                  5
#define A6                  6
#define A7                  7

//Digital I/O
#define PD0_PIN             PIND0
#define PD0_RPORT		    PIND
#define PD0_WPORT		    PORTD
#define PD0_DDR             DDRD	  
#define PD0_PWM             NULL
#define PD0_ANALOG		    NULL

#define PD1_PIN             PIND1
#define PD1_RPORT		    PIND
#define PD1_WPORT		    PORTD
#define PD1_DDR             DDRD
#define PD1_PWM             NULL
#define PD1_ANALOG          NULL

#define PD2_PIN             PIND2
#define PD2_RPORT           PIND
#define PD2_WPORT           PORTD
#define PD2_DDR             DDRD
#define PD2_PWM             NULL
#define PD2_ANALOG          NULL

#define PD3_PIN             PIND3
#define PD3_RPORT           PIND
#define PD3_WPORT           PORTD
#define PD3_DDR             DDRD
#define PD3_PWM             NULL
#define PD3_ANALOG          NULL

#define PD4_PIN             PIND4
#define PD4_RPORT           PIND
#define PD4_WPORT           PORTD
#define PD4_DDR             DDRD
#define PD4_PWM             NULL
#define PD4_ANALOG          NULL

#define PD5_PIN             PIND5
#define PD5_RPORT           PIND
#define PD5_WPORT           PORTD
#define PD5_DDR             DDRD
#define PD5_PWM             NULL
#define PD5_ANALOG          NULL

#define PD6_PIN             PIND6
#define PD6_RPORT           PIND
#define PD6_WPORT           PORTD
#define PD6_DDR             DDRD
#define PD6_PWM             NULL
#define PD6_ANALOG          NULL

#define PD7_PIN             PIND7
#define PD7_RPORT           PIND
#define PD7_WPORT           PORTD
#define PD7_DDR             DDRD
#define PD7_PWM             NULL
#define PD7_ANALOG          NULL

#define PB0_PIN             PINB0
#define PB0_RPORT           PINB
#define PB0_WPORT           PORTB
#define PB0_DDR             DDRB
#define PB0_PWM             NULL
#define PB0_ANALOG          NULL

#define PB1_PIN             PINB1
#define PB1_RPORT           PINB
#define PB1_WPORT           PORTB
#define PB1_DDR             DDRB
#define PB1_PWM             NULL
#define PB1_ANALOG          NULL

#define PB2_PIN             PINB2
#define PB2_RPORT           PINB
#define PB2_WPORT           PORTB
#define PB2_DDR             DDRB
#define PB2_PWM             NULL
#define PB2_ANALOG          NULL

#define PB3_PIN             PINB3
#define PB3_RPORT           PINB
#define PB3_WPORT           PORTB
#define PB3_DDR             DDRB
#define PB3_PWM             NULL
#define PB3_ANALOG          NULL

#define PB4_PIN             PINB4
#define PB4_RPORT           PINB
#define PB4_WPORT           PORTB
#define PB4_DDR             DDRB
#define PB4_PWM             NULL
#define PB4_ANALOG          NULL

#define PB5_PIN             PINB5
#define PB5_RPORT           PINB
#define PB5_WPORT           PORTB
#define PB5_DDR             DDRB
#define PB5_PWM             NULL
#define PB5_ANALOG          NULL

#define PC0_PIN             PINC0
#define PC0_RPORT           PINC
#define PC0_WPORT           PORTC
#define PC0_DDR             DDRC
#define PC0_PWM             NULL
#define PC0_ANALOG          A0

#define PC1_PIN             PINC1
#define PC1_RPORT           PINC
#define PC1_WPORT           PORTC
#define PC1_DDR             DDRC
#define PC1_PWM             NULL
#define PC1_ANALOG          A1

#define PC2_PIN             PINC2
#define PC2_RPORT           PINC
#define PC2_WPORT           PORTC
#define PC2_DDR             DDRC
#define PC2_PWM             NULL
#define PC2_ANALOG          A2

#define PC3_PIN             PINC3
#define PC3_RPORT           PINC
#define PC3_WPORT           PORTC
#define PC3_DDR             DDRC
#define PC3_PWM             NULL
#define PC3_ANALOG          A3

#define PC4_PIN             PINC4
#define PC4_RPORT           PINC
#define PC4_WPORT           PORTC
#define PC4_DDR             DDRC
#define PC4_PWM             NULL
#define PC4_ANALOG          A4

#define PC5_PIN             PINC5
#define PC5_RPORT           PINC
#define PC5_WPORT           PORTC
#define PC5_DDR             DDRC
#define PC5_PWM             NULL
#define PC5_ANALOG          A5

#define PC6_PIN             PINC6
#define PC6_RPORT           PINC
#define PC6_WPORT           PORTC
#define PC6_DDR             DDRC
#define PC6_PWM             NULL
#define PC6_ANALOG          NULL

// Analog only pins
#define A6_ANALOG           A6
#define A7_ANALOG           A7



#endif // UNIT_TEST

#endif /* IOMAP_ARDUINOPROMINI_H_ */
