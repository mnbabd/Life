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
 * 
 */

#include "logging.h"

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
 * @return int -  What is the meaning of what's left behind? Will life return? It has to!
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

    Print_Log(Log_Info, "Hello?");


    return Move_On;
}