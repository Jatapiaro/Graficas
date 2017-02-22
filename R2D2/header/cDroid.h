/*
* WRITE YOUR NAME/ID HERE
*/

#pragma once
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
	#include <time.h>
	#include <stdio.h>
	#include <math.h>
#else
	#include "freeglut.h"
	#include <time.h>
	#include <stdio.h>
	#include <math.h>
#endif

#include "cSphere.h"
#include "cCylinder.h"
#include "cCube.h"

class Droid
{
public:
    
	Droid();
	~Droid();
    void draw();
    void update();
    
    Sphere *head;
    Cylinder *body;
    Cube *trompa,*leftArm,*leftLittleArm,*rightArm,
        *rightLittleArm,*centerArm,*centerLittleArm;
    
    
    float headRotation,shoulderRotation,movementFloat;
    bool left,shoulder,movement;

};
