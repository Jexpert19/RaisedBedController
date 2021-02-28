#include "ADC.h"

#include "IO/RBCTL_hardware.h"

// Initalize module
void ADC_init(){
    // Set voltage reference input
    ADMUX |= (ADC_REF << REFS0);
            
    // Set ADC-input-clock prescaler
    ADCSRA |= (ADC_PRESCALER << ADPS0);
            
    // Enable ADC by setting ADC Enable bit
    SBI(ADCSRA, ADEN);
    
    // Dummy conversation:
    
    // Start conversation
    ADCSRA |= (1 << ADSC);
    
    // Wait until measurement finished
    while (ADCSRA & (1<<ADSC));
    
    // Dump result
    (void) ADC;
}

// Single ADC read
uint16_t ADC_read(uint8_t chanel){
    // Select input chanel
    ADMUX = (ADMUX & ~(0x0F)) | (chanel & 0x0F);
    
    // Start conversation
    ADCSRA |= (1 << ADSC);
    
    // Wait until measurement finished
    while (ADCSRA & (1<<ADSC));
    
    // ADC result
    return ADC;
}

// Read ADC and calculate average for nsamples
uint16_t ADC_Read_Avg( uint8_t channel, uint8_t nsamples ){
    // Buffer for average calculation
    uint32_t sum = 0;

    for(uint8_t i = 0; i < nsamples; ++i ){
        sum += ADC_read( channel );
    }

    return (uint16_t)( sum / nsamples );
}
