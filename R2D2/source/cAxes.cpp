/*
* Sergio Ruiz.
*
* TC3022. Computer Graphics Course.
* Transformations exercise template.
*/

#include "cAxes.h"

Axes::Axes(float _scale)
{
	scale = _scale;
}

Axes::~Axes()
{
}

void Axes::draw()
{
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(scale, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, scale, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, scale);
	}
	glEnd();
	glLineWidth(1.0f);
}
