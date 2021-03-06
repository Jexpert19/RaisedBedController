/* 
 * File:   menu.h
 * Author: janni
 *
 * Created on 28. Dezember 2020, 14:44
 */

#ifndef MENU_H
#define	MENU_H

#ifdef	__cplusplus
extern "C" {
#endif
 
struct menu_item{
    const char* name;
    struct menu_item* previous_item;
    struct menu_item* next_items[];
    (void)(execute*)(void);
};
    


#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

