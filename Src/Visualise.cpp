/**
 * @file Visualise.cpp
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#include "Visualise.h"

#include <GL/glut.h>
#include <assert.h>

#define LOG_LEVEL (Log_Debug)
#include "logging.h"

//callback to render the desired details
void render();

static Visualise* vis_obj = nullptr;

Visualise::Visualise(Simulation &sim) :
m_simulation(sim)
{
    //We're limited to only one observable reality
    assert(vis_obj == nullptr);
    vis_obj = this;

    //Initialise environment
    display_init();
}

void Visualise::Draw()
{

}

void Visualise::display_init()
{
    //We ignore any glut compatible args provided.
    int argc = 0;
    char* argv[] = {};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE); // Use single display buffer.
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glutCreateWindow("Life");
    glutFullScreen();
    glutDisplayFunc(render);
    glutMainLoop();
}


void render()
{
    LOG_DEBUG("display triggered");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset The Projection Matrix

    if(vis_obj)
    {
        vis_obj->Draw();
    }

    glFlush();
}
