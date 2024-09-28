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

Visualise::Visualise()
{
    //We're limited to only one observable reality
    assert(vis_obj == nullptr);
    vis_obj = this;

    //Initialise environment
    Display_Init();

}

Visualise::~Visualise()
{
    if (m_simulation)
    {
        delete m_simulation;
    }
}

void Visualise::Update()
{
    if(m_simulation)
    {
        m_simulation->Tick();
        glutPostRedisplay();
    }
}

void Visualise::Draw()
{
    if(m_simulation == nullptr)
    {
        //Tries to achieve squarity
        Sim_Init();
    }

    uint16_t rows = m_simulation->Get_Rows();
    uint16_t cols = m_simulation->Get_Cols();

    //does not ensure squarity
    static double x_size = (2.0 / (double)cols);
    static double y_size = (2.0 / (double)rows);


    for(uint16_t r = 0; r < rows; r++)
    {
        double y_offset = (y_size * (double)r) - 1.0;
        for(uint16_t c = 0; c < cols; c++)
        {
            double x_offset = (x_size * (double)c) - 1.0;
            bool state = m_simulation->Get_State(r,c);

            if(state)
            {
                glColor3b(33,121,66);
            }
            else
            {
                glColor3b(3,3,11);
            }
            glRectd(x_offset, y_offset, x_offset + x_size, y_offset + y_size);
        }
    }
}

void Visualise::Display_Init()
{
    //We ignore any glut compatible args provided.
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Use single display buffer.
    glutInitWindowSize(1980, 1080);
    glutInitWindowPosition(100, 100);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glutCreateWindow("Life");
    glutFullScreen();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset The Projection Matrix
    glutDisplayFunc(render);
}

void Visualise::Sim_Init()
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    Simulation* sim = nullptr;

    int granularity = 75;
    if(width > height)
    {
        sim = new Simulation(granularity, (double)granularity * ((double)width/(double)height));
    }
    else
    {
        sim = new Simulation((double)granularity * ((double)height/(double)width),granularity);
    }
    //[todo] make it based on resolution
    sim->Init();
    m_simulation = sim;
}

void render()
{
    LOG_DEBUG("display triggered");

    if(vis_obj)
    {
        vis_obj->Draw();
    }

    glFlush();
    glFinish();
    // glutSwapBuffers();
}
