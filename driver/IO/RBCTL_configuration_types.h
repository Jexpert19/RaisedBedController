/* 
 * File:   RBCTL_configuration_types.h
 * Author: Jannis Diekmann
 *
 * Created on 17. Januar 2021, 11:11
 */

#ifndef RBCTL_CONFIGURATION_TYPES_H
#define	RBCTL_CONFIGURATION_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif


// PCB versions:
    
    
#define RBCTL_PCB_V1_0                              10

    

// Options:

// flow control TYPE
#define FLOW_CONTROL_EASY_PUMP_OR_VALVE             50          //Just a relay output
    

// Enable real-time-clock TYPE
#define RTC_DS1307_AT24C32_MODULE                   100


// log log-level  
//requires RBCTL_RTC DS1307
#define LOG_OFF                                     110
#define LOG_ALL                                     111
    
    
// Enable the user interface TYPE
#define UI_RBCTL_PCB_V1_0                           120
    
    
// Enable humidity sensor TYPE
//#define HUMIDITY_SENSOR_CAPACITIVE                130

    
// Enable temperature sensor + TYPE
//#define TEMPERATURE_SENSOR                        140
    
    
// fill level sensor in water reservoir TYPE
#define FILL_LEVEL_SENSOR_EASY_ACTIVE_HIGH          150         //Just a switch that indicates an empty reservoir with a high state
#define FILL_LEVEL_SENSOR_EASY_ACTIVE_LOW           151         //The same but low state when empty
    
    
/* Enable light sensor + TYPE
 * Types:
 * - LDRxxx?
 */
//#define RBCTL_LIGHT_SENSOR                        160


/* Enable ventilation fan for e.g. a greenhouse
 * Types:
 * - VENTILATION_FAN_EASY: 
 */
//#define RBCTL_VENTILATION_FAN                     170         //just a relay output for turning the fan on and off

    
/*Enable flowmeter + TYPE
 * Types:
 * - 
 */
//#define RBCTL_FLOWMETER                           180


// SOLAR-PANEL???
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* RBCTL_CONFIGURATION_TYPES_H */

