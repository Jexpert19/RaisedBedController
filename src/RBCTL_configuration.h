/* 
 * File:   RBCTL_configuration.h
 * Author: Jannis Diekmann
 *
 * Created on 16. Januar 2021, 14:50
 */

#ifndef RBCTL_CONFIGURATION_H
#define	RBCTL_CONFIGURATION_H

#ifdef	__cplusplus
extern "C" {
#endif


//Select PCB
#define RBCTL_PCB_VERSION RBCTL_PCB_V1_0
   
   
/* Enable pumps
 */
#define RBCTL_PUMPS_COUNT 1


    
/* Enable real-time-clock + TYPE
 * Types:
 * - 
 */
#define RBCTL_RTC 


/* Enable log + log-level
 *  
 * requires RBCTL_RTC DS1307
 * 
 * Level:
 * - LOG_ALL
 */
//#define RBCTL_LOG LOG_ALL
    
    
/* Enable the user interface + TYPE
 * Types:
 * - UI_RBCTL_PCB_V1_0
 */ 
//#define RBCTL_UI UI_RBCTL_PCB_V1_0
    
    
// Enable humidity sensor + TYPE
//#define RBCTL_HUMIDITY_SENSOR
// Number of sensors used
//#define RBCTL_HUMIDITY_SENSOR_COUNT 0
    
    
// Enable temperature sensor + TYPE
//#define RBCTL_TEMPERATURE_SENSOR
//Temperature sensors count
//#define RBCTL_TEMPERATURE_SENSOR_COUNT 0
    
    
/* Enable fill level sensor in water reservoir + TYPE
 * Types:
 * - FILL_LEVEL_SENSOR_EASY_ACTIVE_HIGH     //Just a switch that indicates an empty reservoir with a high state
 * - FILL_LEVEL_SENSOR_EASY_ACTIVE_LOW      //The same but low state when empty
 */
#define RBCTL_FILL_LEVEL_SENSOR FILL_LEVEL_SENSOR_EASY_ACTIVE_LOW
    
    
/* Enable light sensor + TYPE
 * Types:
 * - LDRxxx?
 */
//#define RBCTL_LIGHT_SENSOR


/* Enable ventilation fan for e.g. a greenhouse + TYPE
 * Types:
 * - EASY: just a relay output for turning the fan on and off
 */
//#define RBCTL_VENTILATION_FAN

    
/*Enable flowmeter + TYPE
 * Types:
 * - 
 */
//#define RBCTL_FLOWMETER

    
// SOLAR-PANEL???

    
#ifdef	__cplusplus
}
#endif

#endif	/* RBCTL_CONFIGURATION_H */

