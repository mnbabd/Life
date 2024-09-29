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
#endif

#include <atomic>

typedef uint64_t time_ms_raw_t;
typedef std::atomic<time_ms_raw_t> time_ms_t;

class Time_Stamp
{
    public:
    Time_Stamp();

    Time_Stamp(time_ms_t epoch_ms);

    Time_Stamp(Time_Stamp& ts);

    static time_ms_t Get_CurrentTime_Epoch_ms();

    time_ms_t MilliSeconds_To(Time_Stamp& ts);

    time_ms_t Get_Timestamp_ms();

    void Set_Timestamp_ms(time_ms_t ts_ms);

    void Set_To_CurrentTime();


    friend bool operator<(Time_Stamp& lhs, Time_Stamp& rhs);

    friend bool operator>(Time_Stamp& lhs, Time_Stamp& rhs);

    Time_Stamp operator+(Time_Stamp& rhs);

    Time_Stamp operator-(Time_Stamp& rhs);

    Time_Stamp operator+(time_ms_raw_t rhs);

    protected:
    time_ms_t m_timestamp_ms = 0;
};


#endif