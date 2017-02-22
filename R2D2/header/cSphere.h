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

class Sphere
{
public:
	Sphere(float _radius, int _slices, int _stacks, float r, float g, float b);
	~Sphere();

	void draw();

	float red;
	float green;
	float blue;
	float radius;
	int slices;
	int stacks;
};
