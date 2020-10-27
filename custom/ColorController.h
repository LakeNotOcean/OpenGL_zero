#pragma once
#include "../GL/freeglut.h"
#include "global.h"

namespace ColorController
{
	const GLfloat maxRGBvalue = 1.0f;
	const GLfloat minRGBvalue = -1.0f;
	const GLfloat step = 0.05f;
	const int maxColorIndex = 4;
	extern bool isDynColor;
	extern int colorIndex;
	void ChangeColor();
}