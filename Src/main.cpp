/**
 * @file main.cpp
 * @author Muneeb (mnb.abd@gmail.com)
 * @brief Look for the main purpose of life. Some say it is a stream of stimuli triggered by a chain of events.
 * 
 * NOTE: This repository and code-base may not contain the most helpful comments if you are trying to make sense of things.
 * 
 * Then again, search for meaning is never easy.
 * 
 * @copyright Copyright (c) 2024 Muneeb - All Rights Reserved.
 */


#ifndef MAIN_LOG_LEVEL
#define MAIN_LOG_LEVEL (Log_Info)
#endif
#define LOG_LEVEL MAIN_LOG_LEVEL
#include "logging.h"


#include "Visualise.h"
#include "Simulation.h"
#include "Time_Stamp.h"

#include <stdio.h>
#include <GL/glut.h>


static Visualise* visualiser = nullptr;

/**
 * @brief 
 */
void Tick_Tock(int time_ms);


/**
 * @brief What may cause an end to main. What is the meaning of what's left behind.
 */
enum life_returns
{
    Screech = -1, /*!< Life has collapsed in on itself. An unforeseen annihilation. */
    Move_On = 0,  /*!< Peacefully moved on. What some may consider a Success. */
};


/**
 * @brief You may give various arguments. It rarely makes a difference, but that doesn't mean it never does.
 * 
 * @param argc - How much will you argue?
 * @param argv - If only I had a place to put all these arguments.
 * @return int -  What's left behind? Will life return? It has to!
 */
int main(int argc, char* argv[])
{
    //Well lets print us a nice looking banner.
    printf(R"(
                                    
      _|       _|     _|_|          
      _|            _|       _|_|   
      _|       _| _|_|_|_| _|_|_|_| 
      _|       _|   _|     _|       
      _|_|_|_| _|   _|       _|_|_| 
)""\r\n\n\n");

    glutInit(&argc, argv);
    
    for (int i = 0; i < argc; i++)
    {
        LOG_VERBOSE("Argument#%02d: %s", i, argv[i]);
    }

    Visualise vis;
    visualiser = &vis;

    glutTimerFunc(750, Tick_Tock, 0);
    glutMainLoop();
    bool running = true;

    return Move_On;
}

void Tick_Tock(int time_ms)
{
    static uint32_t t = 0;
    static const uint32_t freq_ms = 250;

    if(visualiser == nullptr)
    {
        //nothing to do
        return;
    }

    //Get current time
    Time_Stamp t_now = Time_Stamp::Get_CurrentTime_Epoch_ms();

    //Determine next run
    Time_Stamp t_next = t_now + freq_ms;
    
    LOG_VERBOSE("t_now=%" PRIu64 ", t=%u",t_now.Get_Timestamp_ms(), t);
    t++;

    //The Game
    visualiser->Update();

    //Update current time
    t_now.Set_To_CurrentTime();

    //determine time left
    time_ms_raw_t wait_time = t_now.MilliSeconds_To(t_next);

    //Periodic Task
    if(wait_time)
    {
        // LOG_VERBOSE("t_next_ms=%u, t_ms=%u, t_next_ms - t_ms=%u",t_next_ms, t_ms, t_next_ms - t_ms);
        glutTimerFunc(wait_time, Tick_Tock, 0);
        // glutTimerFunc(t_next - t_now, Tick_Tock, t_ms);
        // glutTimerFunc(freq_ms, Tick_Tock, t_ms);
    }
    else
    {
        LOG_WARNING("Overrun! (t=%d, t_now=%" PRIu64 ")", t, t_now.Get_Timestamp_ms());
        glutTimerFunc(150, Tick_Tock, 0);
    }
}
