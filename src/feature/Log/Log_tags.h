/* 
 * File:   Log_tags.h
 * Author: Jannis Diekmann
 *
 * Created on 6. Februar 2021, 10:31
 */

#ifndef LOG_TAGS_H
#define	LOG_TAGS_H

#ifdef	__cplusplus
extern "C" {
#endif



// Events, that can cause a log entry:
// Max number of elements limited by Log_entry in "Log.c"
// Changes must be made in "Log_tags.c" to !!!

enum Log_tags{
	Log_tag_error,
    Log_tag_warning,
    Log_tag_info,
	Log_tag_debug
};

// String names of Log_tags
extern const char* Log_tagStrings[];


#ifdef	__cplusplus
}
#endif

#endif	/* LOG_TAGS_H */

