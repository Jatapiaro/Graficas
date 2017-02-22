/*
* Sergio Ruiz.
*
* TC3022. Computer Graphics Course.
* Transformations exercise template.
*/

#include "cCylinder.h"

Cylinder::Cylinder(double bottomR, double topR, double _height, int _slices, int _stacks, float r, float g, float b)
{
	quadric = gluNewQuadric();
	bottomRadius = bottomR;
	topRadius = topR;
	height = _height;
	slices = _slices;
	stacks = _stacks;
	red = r;
	green = g;
	blue = b;
}

/*
 * Free memory 
 */
Cylinder::~Cylinder()
{
	delete quadric;
}

/*
 * gluCylinder draws a cylinder oriented along the z axis. 
 * The base of the cylinder is placed at z = 0 and the top at z = height. 
 * A cylinder is subdivided around the z axis into slices and along the z axis into stacks.
 * Note that if top is set to 0.0, this routine generates a cone.
 */
void Cylinder::draw()
{
	glColor3f(red, green, blue);
	gluCylinder(quadric, bottomRadius, topRadius, height, slices, stacks);
}
