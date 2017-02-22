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

class Axes
{
public:
	Axes(float _scale);
	~Axes();

	void draw();

	float scale;
};
