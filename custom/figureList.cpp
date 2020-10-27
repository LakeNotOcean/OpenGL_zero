#include "figureList.h"
#include <iostream>

using namespace std;

void makeList(void)
{
    for (int i = 0; i < vecf.size(); ++i)
    {
        glBegin(GL_TRIANGLES);
        glNormal3d(vecn[vecf[i].c - 1][0], vecn[vecf[i].c - 1][1], vecn[vecf[i].c - 1][2]);
        glVertex3d(vecv[vecf[i].a - 1][0], vecv[vecf[i].a - 1][1], vecv[vecf[i].a - 1][2]);
        glNormal3d(vecn[vecf[i].f - 1][0], vecn[vecf[i].f - 1][1], vecn[vecf[i].f - 1][2]);
        glVertex3d(vecv[vecf[i].d - 1][0], vecv[vecf[i].d - 1][1], vecv[vecf[i].d - 1][2]);
        glNormal3d(vecn[vecf[i].i - 1][0], vecn[vecf[i].i - 1][1], vecn[vecf[i].i - 1][2]);
        glVertex3d(vecv[vecf[i].g - 1][0], vecv[vecf[i].g - 1][1], vecv[vecf[i].g - 1][2]);
        glEnd();
    }
    cout << "List is made" << endl;
}