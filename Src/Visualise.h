/**
 * @file Visualise.h
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#ifndef VISUALISE_H
#define VISUALISE_H

#include "Simulation.h"

class Visualise
{
    public:
    Visualise(Simulation& sim);

    void Draw();

    protected:
    /**
     * @brief Creates a blank fullscreen window with rendering function initialised
     */
    void display_init();

    Simulation& m_simulation;
};

#endif