/*
* Sergio Ruiz.
*
* TC3022. Computer Graphics Course.
* Transformations exercise template.
*/

#include "cSphere.h"

Sphere::Sphere(float _radius, int _slices, int _stacks, float r, float g, float b)
{
	radius = _radius;
	red = r;
	green = g;
	blue = b;
	slices = _slices;
	stacks = _stacks;
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
	glColor3f(red, green, blue);
	glutSolidSphere(radius, slices, stacks);
}
