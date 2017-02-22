/*
* Sergio Ruiz.
*
* TC3022. Computer Graphics Course.
* Transformations exercise template.
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

class Cube
{
public:
	Cube(float _side, float r, float g, float b);
	~Cube();

	void draw();

	float side;
	float red;
	float green;
	float blue;
};
