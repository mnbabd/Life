/**
 * @file Visualise.h
 * @author Muneeb (mnb.abd@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-09-28
 *
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 *
 */

#include <GL/glut.h>
#include "logging.h"

// Displays a window with a square inside.
void display()
{
    LOG_DEBUG("display triggered");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Reset The Projection Matrix

    // glBegin(GL_POLYGON);
    // glColor3f(0xff,0xff,0xff);
    // glVertex3f(0.0, 0.0, 0.0);
    // glVertex3f(1.0, 0.0, 0.0);
    // glVertex3f(1.0, 1.0, 0.0);
    // glVertex3f(0.0, 1.0, 0.0);
    // glEnd();

    glFlush();
}

// Displays a window with a square inside.
void display_init(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE); // Use single display buffer.
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glutCreateWindow("Life");
    glutDisplayFunc(display);
    glutMainLoop();
}