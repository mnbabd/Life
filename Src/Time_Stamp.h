/**
 * @file Time.h
 * @author Muneeb (mnb.abd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-29
 * 
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#ifndef TIME_STAMP_H
#define TIME_STAMP_H

#include <stdint.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#define sleep_ms(_T_MS) Sleep(_T_MS) /*[todo]confirm*/
#elif linux
#include <unistd.h>
#define TIMESPEC_TO_MS(_TSPEC) ((_TSPEC.tv_sec * 1e3) + (_TSPEC.tv_nsec / 1e-6))
// #define TIMESPEC_TO_MS(_TSPEC) (_TSPEC.tv_nsec / 1e-6)
#endif


typedef uint32_t time_ms_t;

class Time_Stamp
{
    public:
    Time_Stamp();

    protected:
    time_ms_t m_timestamp = 0;
};


#endif