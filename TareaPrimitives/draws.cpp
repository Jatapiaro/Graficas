/*
 * Jacobo Tapia de la Rosa
 * A01336590
 *
 * TC3022. Computer Graphics Course.
 * Homework 2.
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Point{
   	public:
    	float x,y;
};

int shape,primitive,mode,color,window,step;
Point circle_points[360],rectangle_points[4];

void processMenu(int val){
    if(val == 666){
        glutDestroyWindow(window);
        exit(0);
    }else if(val >= 1 && val <= 6){
        if(val == 1){
            shape = 360;
        }else{
            shape = val;
        }
    }else if(val == 101 || val == 102){
        mode = val;
    }else if(val >= 201 && val <= 205){
        primitive = val;
        /*
        * Step is a variable to know 
        * how to move in the drawing
        * for lines we need to move from 2
        * point from 2 to points
        */
        if(val == 202){
            step = 2;
        }else{
            step = 1;
        }
    }else if(val >= 301 && val <=304){
        color = val;
    }
}

void createMenu(){

    int menu,shape_menu,mode_menu,primitive_menu,color_menu;

    shape_menu = glutCreateMenu(processMenu);
    glutAddMenuEntry("Triangle",3);
    glutAddMenuEntry("Pentagon",5);
    glutAddMenuEntry("Hexagon",6);
    glutAddMenuEntry("Rectangle",2);
    glutAddMenuEntry("Rhombus",4);
    glutAddMenuEntry("Circle",1);

    mode_menu = glutCreateMenu(processMenu);
    glutAddMenuEntry("Solid",101);
    glutAddMenuEntry("Wireframe",102);

    primitive_menu = glutCreateMenu(processMenu);
    glutAddMenuEntry("GL_POINTS",201);
    glutAddMenuEntry("GL_LINES",202);
    glutAddMenuEntry("GL_LINE_STRIP",203);
    glutAddMenuEntry("GL_TRIANGLES",204);
    glutAddMenuEntry("GL_TRIANGLE_STRIP",205);

    color_menu = glutCreateMenu(processMenu);
    glutAddMenuEntry("White",301);
    glutAddMenuEntry("Red",302);
    glutAddMenuEntry("Blue",303);
    glutAddMenuEntry("Green",304);

    menu = glutCreateMenu(processMenu);
    glutAddSubMenu("Shape", shape_menu);
    glutAddSubMenu("Mode", mode_menu);
    glutAddSubMenu("Primitive", primitive_menu);
    glutAddSubMenu("Color", color_menu);
    glutAddMenuEntry("Exit", 666);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void init(){

    /*
    * Calculate everything just once :)
    */
	float w,deg_to_rad,radius;

    shape = 3;
    mode = 101;
    primitive = 201;
    step = 1;

	w = 360/360;

	radius = 3.0f;

	deg_to_rad = 0.0174533;

    int i=0;

	for(i = 0; i < 360; i ++){
		float angle;
		Point p;
		angle = deg_to_rad * (float)i;
		p.x = radius * cosf(angle);
		p.y = radius * -sinf(angle);
		circle_points[i] = p;
	}

	glEnable(GL_DEPTH_TEST);     
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glMatrixMode(GL_MODELVIEW);     
	glLoadIdentity(); 

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       // Clear color and depth buffers.
    glLoadIdentity();                       // Reset 3D view matrix.
    gluLookAt(0.0, 0.0, 10.0,  // Where the cam is                 // Where the camera is.
              0.0, 0.0, 0.0,  // Cam pivot                  // To where the camera points at.
              10.0, 0.0, 0.0); // UP vector                  // "UP" vector.
    glPushMatrix();



    if(mode == 101){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }


    glPointSize(5.0f);

    switch(color){
        case 301:
            glColor3d(1.0, 1.0, 1.0);
            break;
        case 302:
            glColor3d(1.0, 0.0, 0.0);
            break;
        case 303:
            glColor3d(0.0, 0.0, 1.0);
            break;
        case 304:
            glColor3d(0.0, 1.0, 0.0);
            break;
    }

    switch(primitive){
        case 201:
            glBegin(GL_POINTS);
            break;
        case 202:
            glBegin(GL_LINES);
            break;
        case 203:
            glBegin(GL_LINE_STRIP);
            break;
        case 204:
            glBegin(GL_TRIANGLES);
            break;
        case 205:
            glBegin(GL_TRIANGLE_STRIP);
            break;
    }

    if(shape!=2){
        int w;
        w = 360/shape;
        for(int i=0;i<=360;i+=(w*step)){
            float x,y,x2,y2;
            x = circle_points[i].x;
            y = circle_points[i].y;

            if(i+w >= 360){
                /*
                * Fills some gap generated on some 
                * odd figures equal or greater than 7
                */
                x2 = circle_points[0].x;
                y2 = circle_points[0].y;
            }else{
                x2 = circle_points[i+w].x;
                y2 = circle_points[i+w].y;
            }
            glVertex3f(x,y,0);
            glVertex3f(0,0,0);
            glVertex3f(x2,y2,0);
            glVertex3f(0,0,0);
            glVertex3f(x,y,0);
            glVertex3f(x2,y2,0);
        }
    }else{

        /*
        * The rectangle is independent of the circle
        * if we use again 4 edges, it will be just another
        * rhombus
        */

        /*
        * Point A - B - C
        */
        glVertex3f(0,-3,0);
        glVertex3f(1.5,-3,0);
        glVertex3f(1.5,3,0);

        /*
        * Point B - C - D
        */
        glVertex3f(1.5,-3,0);
        glVertex3f(1.5,3,0);
        glVertex3f(0,3,0);

        /*
        * Point C - D - A
        */
        glVertex3f(1.5,3,0);
        glVertex3f(0,3,0);
        glVertex3f(0,-3,0);

        /*
        * Point D - A - B
        */
        glVertex3f(0,3,0);
        glVertex3f(0,-3,0);
        glVertex3f(1.5,3,0);
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();                        // Swap the hidden and visible buffers.
}

void idle(){
    glutPostRedisplay();                      // Display again.
}

void reshape(int x, int y){
    glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
    glLoadIdentity();												// Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);		// Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
    glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 4.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}


int main(int argc, char* argv[]){
    glutInit(&argc, argv);                                          // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);       // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    window = glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);                                       // Reshape CALLBACK function.
    glutDisplayFunc(display);                                       // Display CALLBACK function.
    glutIdleFunc(idle);                                             // Idle CALLBACK function.
    createMenu();
    glutMainLoop();                                                 // Begin graphics program.
    return 0;                           // ANSI C requires a return value.
}