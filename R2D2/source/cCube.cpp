/*
* Sergio Ruiz.
*
* TC3022. Computer Graphics Course.
* Transformations exercise template.
*/

#include "cCube.h"

Cube::Cube(float _side, float r, float g, float b)
{
	side = _side;
	red = r;
	green = g;
	blue = b;
}

Cube::~Cube()
{
}

void Cube::draw()
{
	glColor3f(red, green, blue);
	glutSolidCube(side);
}
