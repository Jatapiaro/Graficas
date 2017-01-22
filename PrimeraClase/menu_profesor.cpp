/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Menus example.
 */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#include <stdio.h>
#include <math.h>
#endif

void processMenu(int val);

// MY STATES:
int shape; //0: TEAPOT, 1: TEACUP, 2: TEASPOON

// ROTATION IN DEGREES:
float rotation;

void init()
{
    shape = 0;
    rotation = 0;
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
    
    glRotatef(rotation, 0,1,0);
    if (shape == 0)
    {
        glColor3f(0, 0, 1);
        glutWireTeapot(2.0);
    }
    else if(shape == 1)
    {
        glColor3f(1, 0, 0);
        glutWireTeacup(2.0);
    }
    else
    {
        glColor3f(0, 1, 0);
        glutWireTeaspoon(2.0);
    }
    
    glPopMatrix();
    
    
    glutSwapBuffers();												// Swap the hidden and visible buffers.
}

void idle()															// Called when drawing is finished.
{
    rotation += 0.01f;
    glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
    glLoadIdentity();												// Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);		// Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
    glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
    gluLookAt(0.0, 3.0, 10.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

void addMenus()
{
    // These variables store a GLUT-generated ID.
    // For each menu, you need an integer variable.
    // We'll generate 1 variable:
    int mainMenu;
    
    // Step 1: generate IDs for each menu and
    // assign a callback method (processMenu) for each:
    mainMenu = glutCreateMenu(processMenu);
    
    // Step 2: fill the menus.
    // Activate mainMenu, fill it with submenu1 & submenu 2:
    glutSetMenu(mainMenu);
    glutAddMenuEntry("TEAPOT",		21);
    glutAddMenuEntry("TEACUP",		22);
    glutAddMenuEntry("TEASPOON",	23);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/*
 Callback to process menus
 */
void processMenu(int val)
{
    if (val == 21)
    {
        shape = 0;
    }
    else if(val == 22)
    {
        shape = 1;
    }
    else
    {
        shape = 2;
    }
    
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);											// Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow(argv[0]);
    
    init();
    glutReshapeFunc(reshape);										// Reshape CALLBACK function.
    glutDisplayFunc(display);										// Display CALLBACK function.
    glutIdleFunc(idle);												// Idle CALLBACK function.
    addMenus();
    
    glutMainLoop();													// Begin graphics program.
    return 0;														// ANSI C requires a return value.
}
