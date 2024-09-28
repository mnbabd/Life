/**
 * @file logging.c
 * @brief Oversimplified non-logging logs that are just a printing to stdout interface.
 * 
 * Done this way for readability and ease of access to the interface to add detail if needed.
 * Could be done in other more efficient ways but consider using a proper logging library if it comes to that.
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#include "logging.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

const char* Log_Level_Tags[] = {
"Debug",
"Info",
"Warning",
"Critical",
"Fatal",
};

static_assert(sizeof(Log_Level_Tags)/sizeof(Log_Level_Tags[0]) == Log_Level_Count, "A string tag for each log level needs to be provided.");


void Print_Log(log_level level, const char *format, ...)
{
    //Print the level tag
    if(level < Log_Level_Count)
    {
        printf("%10s: ", Log_Level_Tags[level]);
    }
    else
    {
        printf("%10s: ", "");
    }

    //Now we print the message
    va_list	args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    //Move on to the next line
    printf("\r\n");
}



#ifdef __cplusplus
} // extern "C"
#endif
