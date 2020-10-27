#include "ColorController.h"
#include <iostream>

using namespace figureData;
using namespace ColorController;
using Indexes::GLfloatComp;
using namespace std;

bool ColorController::isDynColor = false;
GLfloat figureData::figureColor[] = {maxRGBvalue,minRGBvalue,minRGBvalue,1.0};

void ColorController::ChangeColor()
{
	if (!GLfloatComp(figureColor[0],minRGBvalue) && !GLfloatComp(figureColor[2],maxRGBvalue) && GLfloatComp(figureColor[1],minRGBvalue))
	{
		figureColor[0]-=step;
		figureColor[2]+=step;
	}
	else if (!GLfloatComp(figureColor[2], minRGBvalue) && !GLfloatComp(figureColor[1], maxRGBvalue) && GLfloatComp(figureColor[0], minRGBvalue))
	{
		figureColor[2] -= step;
		figureColor[1] += step;
	}
	else if (!GLfloatComp(figureColor[1], minRGBvalue) && !GLfloatComp(figureColor[0], maxRGBvalue) && GLfloatComp(figureColor[2], minRGBvalue))
	{
		figureColor[1] -= step;
		figureColor[0] += step;
	}
	cout << "Color is Changed: redColor " << figureColor[0] << " greenColor: " << figureColor[1] << " blueColor: " << figureColor[2] << endl; 
}