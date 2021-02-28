/* 
 * File:   Log_parser.h
 * Author: Jannis Diekmann
 *
 * Created on 10. Februar 2021, 22:01
 */

#ifndef LOG_PARSE_H
#define	LOG_PARSE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Log_entry.h"

void Log_parse_entry(struct Log_entry* entry, char* res);


#ifdef	__cplusplus
}
#endif

#endif	/* LOG_PARSE_H */

