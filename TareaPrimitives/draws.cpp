#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>

class Point{
   	public:
    	float x,y,z;
};

int main_menu,submenu_shape,submenu_primitive;
Point circle_points[360];
Point pivot;

void createMenu(){
    int menu,shape_menu,mode_menu,primitive_menu;
}

void init(){
	float w,deg_to_rad,radius;

	pivot.x = 0.0f;
	pivot.y = 0.0f;
	pivot.z = 0.0f;

	w = 360/360;

	radius = 5.0f;

	deg_to_rad = 0.0174533;

	for(int i =0; i <= 360; i ++){
		float angle;
		Point p;
		angle = deg_to_rad * (float)i;
		p.x = radius * cosf(angle);
		p.y = radius * -sinf(angle);
		p.z = 0.0f;
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
    gluLookAt(0.0, 10.0, 10.0,  // Where the cam is                 // Where the camera is.
              0.0, 0.0, 0.0,  // Cam pivot                  // To where the camera points at.
              0.0, 1.0, 0.0); // UP vector                  // "UP" vector.
    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINE_STRIP);
    {
    	int w,count;
    	w = 360/5;
        count = 1;

    	glVertex3f(0,0,0);

    	for(int i=0;i<=360;i+=w){
    		float x,y,z;
            count++;
    		x = circle_points[i].x;
    		y = circle_points[i].y;
    		z = circle_points[i].z;
            /*if(count == 2){
                count=0;
                glVertex3f(pivot.x,pivot.y,pivot.z);
            }*/
    		glVertex3f(x,y,z);
    	}
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
    glutCreateWindow(argv[0]);
    
    init();
    glutReshapeFunc(reshape);                                       // Reshape CALLBACK function.
    glutDisplayFunc(display);                                       // Display CALLBACK function.
    glutIdleFunc(idle);                                             // Idle CALLBACK function.
    
    glutMainLoop();                                                 // Begin graphics program.
    return 0;                           // ANSI C requires a return value.
}