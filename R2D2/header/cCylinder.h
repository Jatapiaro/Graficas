/*
* Sergio Ruiz.
*
* TC3022. Computer Graphics Course.
* Transformations exercise template.
*/

// See https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluCylinder.xml

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

class Cylinder
{
public:
	Cylinder(double bottomR, double topR, double _height, int _slices, int _stacks, float r, float g, float b);
	~Cylinder();

	void draw();

	GLUquadric* quadric;
	double bottomRadius;
	double topRadius;
	double height;
	int slices;
	int stacks;
	float red;
	float green;
	float blue;
};
