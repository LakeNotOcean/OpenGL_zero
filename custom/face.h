#pragma once
#include <string>

using std::string;

struct face
{
	face();
	face(int _a, int _b, int _c, int _d, int _e, int _f, int _g,int _i, int _h);
	face(int inputMass[]);
	unsigned int a, b, c, d, e, f, g, i, h;
};
