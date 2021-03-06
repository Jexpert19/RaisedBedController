#ifndef UNIT_TEST

#include "RBCTL_PCB_V1_0.h"

void RBCTL_PCB_V1_0_init(void){
    // Init IOs
    IO_SET_OUTPUT(IO_ONBOARD_LED);
    
    ADC_init();
}

#endif
