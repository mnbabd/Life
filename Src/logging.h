/**
 * @file logging.h
 * @brief Oversimplified non-logging logs that are just a printing to stdout interface.
 * 
 * Done this way for readability and ease of access to the interface to add detail if needed.
 * Could be done in other more efficient ways but consider using a proper logging library if it comes to that.
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#ifndef LOGGING_H
#define LOGGING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

typedef enum log_level
{
    Log_Debug = 0,
    Log_Info,
    Log_Warning,
    Log_Critical,
    Log_Fatal,

    Log_Level_Count
} log_level;

extern const char* Log_Level_Tags[];

/**
 * @brief Print Log with the desired level
 * 
 * @param level - Log level to print the message on.
 * @param format - Format string (printf style)
 * @param ... - Data required for the format string
 */
void Print_Log(log_level level, const char *format, ...);

//Defining macros to call the print function with appropriate level. (Yes, I could do it all here. But that's not the point.)
#define LOG_DEBUG(...)     Print_Log(Log_Debug, __VA_ARGS__)
#define LOG_INFO(...)      Print_Log(Log_Info, __VA_ARGS__)
#define LOG_WARNING(...)   Print_Log(Log_Warning, __VA_ARGS__)
#define LOG_CRITICAL(...)  Print_Log(Log_Critical, __VA_ARGS__)
#define LOG_FATAL(...)     Print_Log(Log_Fatal, __VA_ARGS__)


#ifdef __cplusplus
} // extern "C"
#endif

#endif