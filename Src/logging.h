/**
 * @file logging.h
 * @author your name (you@domain.com)
 * @brief Oversimplified non-logging logs that are just a printing to stdout interface.
 * 
 * Done this way for readability and ease of access to the interface to add detail if needed.
 * Could be done in other more efficient ways but consider using a proper logging library if it comes to that.
 * 
 * @version 0.1
 * @date 2024-09-28
 * 
 * @copyright Copyright (c) 2024 Muneeb - All Rights Reserved.
 * 
 */

#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

enum log_level
{
    Log_Debug = 0,
    Log_Info,
    Log_Warning,
    Log_Critical,
    Log_Fatal,

    Log_Level_Count
};

const char* Log_Level_Tags[] = {
"Debug",
"Info",
"Warning",
"Critical",
"Fatal",
};

static_assert(sizeof(Log_Level_Tags)/sizeof(Log_Level_Tags[0]) == Log_Level_Count, "A string tag for each log level needs to be provided.");


//Defining macros to call the print function with appropriate level. (Yes, I could do it all here. But that's not the point.)
#define LOG_DEBUG(...)     Print_Log(Log_Debug, __VA_ARGS__)
#define LOG_INFO(...)      Print_Log(Log_Info, __VA_ARGS__)
#define LOG_WARNING(...)   Print_Log(Log_Warning, __VA_ARGS__)
#define LOG_CRITICAL(...)  Print_Log(Log_Critical, __VA_ARGS__)
#define LOG_FATAL(...)     Print_Log(Log_Fatal, __VA_ARGS__)


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

#endif