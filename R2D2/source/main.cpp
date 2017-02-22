/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Transformations exercise template.
 */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#else
#include "freeglut.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#endif

#include "cAxes.h"
#include "cDroid.h"
// TO-DO: Include robot header:

Axes* axes;
Droid* droid;
int window;
// TO-DO: Declare robot:


void processMenu(int val){
    /*
     *To stop execution quickly
     */
    if(val == 666){
        glutDestroyWindow(window);
        exit(0);
    }
}

void createMenu(){
    int menu;
    menu = glutCreateMenu(processMenu);
    glutAddMenuEntry("Exit", 666);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void init()
{
    axes = new Axes(1.0f);
    droid = new Droid();
    // TO-DO: Instance robot:
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
    glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
    glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
    glPushMatrix();
    {
        axes->draw();
        droid->draw();
        // TO-DO: Draw robot:
        
    }
    glPopMatrix();
    glutSwapBuffers();												// Swap the hidden and visible buffers.
}

void idle()															// Called when drawing is finished.
{
    // TO-DO: Update robot logic-related variables:
    droid->update();
    glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
    glLoadIdentity();												// Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);		// Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
    glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
    gluLookAt(2.0, 1.0, 3.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

int main(int argc, char* argv[])
{
    //srand(time(NULL));
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
    
    // TO-DO: Free memory:
    
    return 0;														// ANSI C requires a return value.
}
