/**
 * @file Time_Stamp.cpp
 * @author Muneeb (mnb.abd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-29
 * 
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#ifndef TIMESTAMP_LOG_LEVEL
#define TIMESTAMP_LOG_LEVEL (Log_Info)
#endif
#define LOG_LEVEL TIMESTAMP_LOG_LEVEL
#include "logging.h"


#include "Time_Stamp.h"

#define DEFAULT_WRAPAROUND_DETECT_MS (2500)
#define TIMESPEC_TO_MS(_TSPEC) ((_TSPEC.tv_sec * 1e3) + (_TSPEC.tv_nsec / 1e6))


// time_ms_t Time_Stamp::g_wrap_around_window_ms = DEFAULT_WRAPAROUND_DETECT_MS;

Time_Stamp::Time_Stamp()
{
    m_timestamp_ms.store(Get_CurrentTime_Epoch_ms());
}

Time_Stamp::Time_Stamp(time_ms_t epoch_ms)
{
    m_timestamp_ms.store(epoch_ms);
}

Time_Stamp::Time_Stamp(Time_Stamp &ts)
{
    Set_Timestamp_ms(ts.Get_Timestamp_ms());
}

time_ms_t Time_Stamp::Get_Timestamp_ms()
{
    return m_timestamp_ms.load();
}

void Time_Stamp::Set_Timestamp_ms(time_ms_t ts_ms)
{
    m_timestamp_ms.store(ts_ms.load());
}

void Time_Stamp::Set_To_CurrentTime()
{
    Set_Timestamp_ms(Get_CurrentTime_Epoch_ms());
}

Time_Stamp Time_Stamp::operator+(Time_Stamp &rhs)
{
    Time_Stamp &lhs = *this;
    time_ms_raw_t lhs_raw = lhs.Get_Timestamp_ms();
    time_ms_raw_t rhs_raw = rhs.Get_Timestamp_ms();

    Time_Stamp temp(lhs_raw + rhs_raw);
    return temp;
}

Time_Stamp Time_Stamp::operator-(Time_Stamp &rhs)
{
    Time_Stamp &lhs = *this;
    time_ms_raw_t lhs_raw = lhs.Get_Timestamp_ms();
    time_ms_raw_t rhs_raw = rhs.Get_Timestamp_ms();

    if(lhs_raw > rhs_raw)
    {
        Time_Stamp temp(lhs_raw - rhs_raw);
        return temp;
    }

    Time_Stamp temp(0);
    return temp;
}

Time_Stamp Time_Stamp::operator+(time_ms_raw_t rhs)
{
    Time_Stamp &lhs = *this;
    time_ms_raw_t lhs_raw = lhs.Get_Timestamp_ms();

    Time_Stamp temp(lhs_raw + rhs);
    return temp;
}

time_ms_t Time_Stamp::Get_CurrentTime_Epoch_ms()
{
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);

    time_ms_raw_t t_ms = TIMESPEC_TO_MS(tv);

    return time_ms_t(t_ms);
}

time_ms_t Time_Stamp::MilliSeconds_To(Time_Stamp &ts)
{
    Time_Stamp &self = *this;
    return (ts-self).Get_Timestamp_ms();
}

bool operator<(Time_Stamp &lhs, Time_Stamp &rhs)
{
    time_ms_raw_t lhs_raw = lhs.Get_Timestamp_ms();
    time_ms_raw_t rhs_raw = rhs.Get_Timestamp_ms();

    return (lhs_raw < rhs_raw);
}

bool operator>(Time_Stamp &lhs, Time_Stamp &rhs)
{

    time_ms_raw_t lhs_raw = lhs.Get_Timestamp_ms();
    time_ms_raw_t rhs_raw = rhs.Get_Timestamp_ms();

    return (lhs_raw > rhs_raw);
}
