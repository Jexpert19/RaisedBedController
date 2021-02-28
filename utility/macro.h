/* 
 * File:   macro.h
 * Author: Jannis Diekmann
 *
 * Created on 16. Januar 2021, 23:04
 */

#ifndef MACRO_H
#define	MACRO_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#define STRINGIFY(n) #n

#define TOSTR(n) STRINGIFY(n)


#ifdef	__cplusplus
}
#endif

#endif	/* MACRO_H */

