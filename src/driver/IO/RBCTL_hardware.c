#include "RBCTL_hardware.h"


void RBCTL_hardware_init(void){
    #if RBCTL_PCB_VERSION == RBCTL_PCB_V1_0
    #include "RBCTL_PCB_V1_0.h"
    RBCTL_PCB_V1_0_init();
    #endif
}
