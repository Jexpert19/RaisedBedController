/* 
 * File:   RBCTL_hardware.h
 * Author: Jannis Diekmann
 *
 * Created on 17. Januar 2021, 11:59
 */

#ifndef RBCTL_HARDWARE_H
#define	RBCTL_HARDWARE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "RBCTL_configuration_types.h"
#include "../../RBCTL_configuration.h"

    
#ifndef RBCTL_PCB_VERSION
    #error "PCB version not defined"
#elif RBCTL_PCB_VERSION == RBCTL_PCB_V1_0
    #include "RBCTL_PCB_V1_0.h"
#endif

// IO Unit
struct unit{
    void (*fun_ptr_activate)  (void);
    void (*fun_ptr_deactivate)(void);
    const char * name;
};

void RBCTL_hardware_init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* RBCTL_HARDWARE_H */

