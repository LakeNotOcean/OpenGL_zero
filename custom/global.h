#pragma once

#include "../vecmath/vecmath.h"
#include "face.h"
#include "../GL/freeglut.h"
#include <cmath>
#include <vector>

using std::vector;

namespace figureData {
    // This is the list of points (3D vectors)
    extern vector<Vector3f> vecv;

    // This is the list of normals (also 3D vectors)
    extern vector<Vector3f> vecn;

    // This is the list of faces (indices into vecv and vecn)
    extern vector<face> vecf;

    extern GLuint theFigure;
    
    extern GLfloat figureColor[4];

    extern float CT[16];
    extern float CT1[16];
}


// You will need more global variables to implement color and position changes

namespace Indexes {
    extern bool isSpin;
    extern float angle;
    extern float lightVertPos;
    extern float lightHorPos;
    const int maxFaceIndex = 9;
    const float maxAngle = 360.0f;
    const float eps = 0.00001f;
    const float pi = 3.14159265f;
    const int windowWidth = 360;
    const int windowHeight = 360;
    bool GLfloatComp(GLfloat a, GLfloat b);
}

namespace MousePos {
    extern float oldX, oldY, oldZ,uX,uZ,uY;
    extern float mouseAngle;
    extern float sphereRad;
    extern float times;
}
