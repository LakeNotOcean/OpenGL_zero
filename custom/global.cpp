#include "global.h"
#include <iostream>
#include <cmath>

vector<Vector3f> figureData::vecv = {};
vector<Vector3f> figureData::vecn = {};
vector<face> figureData::vecf = {};
GLuint figureData::theFigure = {};
float figureData::CT[16]=
{0.0f,0.0f,0.0f,0.0f,
0.0f,0.0f,0.0f,0.0f, 
0.0f,0.0f,0.0f,0.0f, 
0.0f,0.0f,0.0f,0.0f, };
float figureData::CT1[16]=
{ 0.0f,0.0f,0.0f,0.0f,
0.0f,0.0f,0.0f,0.0f,
0.0f,0.0f,0.0f,0.0f,
0.0f,0.0f,0.0f,0.0f, };


float Indexes::lightVertPos = 1.0f;
float Indexes::lightHorPos = 1.0f;
float Indexes::angle = 0.0f;
bool Indexes::isSpin = false;
bool Indexes::GLfloatComp(GLfloat a, GLfloat b)
{
	if (abs(a - b) < eps)
		return true;
	else return false;
}

float MousePos::mouseAngle = 0.0f;
float MousePos::oldX = 0.0f;
float MousePos::oldY = 0.0f;
float MousePos::oldZ = 0.0f;
float MousePos::uX = 0.0f;
float MousePos::uY = 0.0f;
float MousePos::uZ = 0.0f;
float MousePos::sphereRad = std::min(Indexes::windowHeight/2,Indexes::windowWidth/2);
float MousePos::sq = 0.0f;
float MousePos::sqOld = 0.0f;
float MousePos::times = 1.0f;

