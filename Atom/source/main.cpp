//
//  main.cpp
//  Atoms
//
//  Created by Jacobo Tapia on 11/02/17.
//  Copyright © 2017 Jacobo Tapia. All rights reserved.
//
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #include "freeglut.h"
    #include <stdio.h>
    #include <math.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cBerylliumAtom.h"

float rot;
int window,type;
BerylliumAtom *ba;

void processMenu(int val){
    /*
     *To stop execution quickly
     */
    if(val == 666){
        glutDestroyWindow(window);
        exit(0);
    }else if(val==0){
        type = 0;
    }else if(val==1){
        type = 1;
    }
}

void createMenu(){
    int menu,modeMenu;
    
    modeMenu = glutCreateMenu(processMenu);
    glutAddMenuEntry("Wireframe",0);
    glutAddMenuEntry("Solid",1);
    
    menu = glutCreateMenu(processMenu);
    glutAddSubMenu("Mode", modeMenu);
    glutAddMenuEntry("Exit", 666);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init()
{
    ba = new BerylliumAtom();
    rot = 0.0f;
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
    glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
    glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
    ba->draw(type);
    glutSwapBuffers();												// Swap the hidden and visible buffers.
}

void idle()															// Called when drawing is finished.
{
    rot += 0.01f;
    glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);	 // 2D								// Go to 2D mode.
    glLoadIdentity();												// Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);		// Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW); // 3D										// Go to 3D mode.
    glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
    gluLookAt(0.0, 0.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 10.0, 0.0);
    display();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);											// Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    window = glutCreateWindow(argv[0]);
    createMenu();
    init();
    glutReshapeFunc(reshape);										// Reshape CALLBACK function.
    glutDisplayFunc(display);										// Display CALLBACK function.
    glutIdleFunc(idle);												// Idle CALLBACK function.
    
    glutMainLoop();													// Begin graphics program.
    return 0;														// ANSI C requires a return value.
}
