#include "face.h"

face::face():
	a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0) {}


face::face(int _a, int _b, int _c, int _d, int _e, int _f, int _g,int _h,int _i) :
	a(_a), b(_b), c(_c), d(_d), e(_e), f(_f), g(_g), h(_h), i(_i) {}

face::face(int InputMas[])
{
	a = InputMas[0];
	b = InputMas[1];
	c = InputMas[2];
	d = InputMas[3];
	e = InputMas[4];
	f = InputMas[5];
	g = InputMas[6];
	h = InputMas[7];
	i = InputMas[8];
}