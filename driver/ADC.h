/* 
 * File:   ADC.h
 * Author: Jannis Diekmann
 *
 * Created on 22. Januar 2021, 18:29
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
    
#define ADC_REF_EXTERNAL_AREF   0b00
#define ADC_REF_AVCC            0b01
#define ADC_REF_INTERNAL_1_1V   0b11 
    
#define ADC_REF                 ADC_REF_AVCC    
    
    
#define ADC_PRESCALER_2         0b001
#define ADC_PRESCALER_4         0b010
#define ADC_PRESCALER_8         0b011
#define ADC_PRESCALER_16        0b100
#define ADC_PRESCALER_32        0b101
#define ADC_PRESCALER_64        0b110
#define ADC_PRESCALER_128       0b111
    
#define ADC_PRESCALER           ADC_PRESCALER_16
    
    
void ADC_init(void);

uint16_t ADC_read(uint8_t chanel);

uint16_t ADC_Read_Avg( uint8_t channel, uint8_t nsamples);

    
#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

