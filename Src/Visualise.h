/**
 * @file Visualise.h
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#ifndef VISUALISE_H
#define VISUALISE_H

#include <GL/glut.h>

class Visualise
{
    public:
    Visualise();

    protected:
    /**
     * @brief Creates a blank fullscreen window with rendering function initialised
     */
    void display_init();
};

#endif