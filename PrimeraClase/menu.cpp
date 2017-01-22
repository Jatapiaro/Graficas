
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>

float rotationY; 
int option,menu_id;

void menu(int op){
    option = op;
    glutPostRedisplay();
}

void createMenu(void){
    glutCreateMenu(menu);
    glutAddMenuEntry("Torus", 0);
    glutAddMenuEntry("Teapot", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init() // FOR GLUT LOOP
{
    glEnable(GL_DEPTH_TEST);      // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0); // Clear the color state.
    glMatrixMode(GL_MODELVIEW);     // Go to 3D mode.
    glLoadIdentity();         // Reset 3D view matrix.
}

void display()              // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       // Clear color and depth buffers.
    glLoadIdentity();                       // Reset 3D view matrix.
    gluLookAt(0.0, 10.0, 10.0,  // Where the cam is                 // Where the camera is.
              0.0, 0.0, 0.0,  // Cam pivot                  // To where the camera points at.
              0.0, 1.0, 0.0); // UP vector                  // "UP" vector.
    glRotatef(rotationY*50.0f, 0, 1, 0);
    if(option == 0){
        glPushMatrix();
        {
            glColor3d(1.0, 0.0, 0.0); // Yellow
            //glRotatef(rotationY*10.0f, 0, 1, 0); // Rotating slow
            glutWireTorus(1.0, 2.5, 10, 10);
        }
        glPopMatrix();
    }else if(option == 1){
        /*glPushMatrix();
        {
            glColor3f(1.0f, 1.0f, 0.0f); // Yellow
            glRotatef(rotationY*10.0f, 0, 1, 0); // Rotating slow
            glutWireTeapot(3);
        }
        glPopMatrix();*/

        glColor3f(1.0f, 1.0f, 0.0f);

        glPointSize(8.0f);
        
        glBegin(GL_POINTS);
        {
            //Create points
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(0,2,0);
            glVertex3f(0,0,4);
        }
        glEnd();


    }
    
    glutSwapBuffers();                        // Swap the hidden and visible buffers.
}

void idle()                             // Called when drawing is finished.
{
    rotationY += 0.01f;
    glutPostRedisplay();                      // Display again.
}

void reshape(int x, int y)                      // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                  // Go to 2D mode.
    glLoadIdentity();                       // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);   // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                   // Go to 3D mode.
    glViewport(0, 0, x, y);                     // Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 4.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                      // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);   // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG IS COOL");
    createMenu();
    init();
    glutReshapeFunc(reshape);                   // Reshape CALLBACK function.
    glutDisplayFunc(display);                   // Display CALLBACK function.
    glutIdleFunc(idle);                       // Idle CALLBACK function.
    glutMainLoop();                         // Begin graphics program.
    return 0;                           // ANSI C requires a return value.
}
