#include "KeysFunctions.h"
#include "../GL/freeglut.h"
#include <iostream>
#include <cmath>
#include "ColorController.h"

using namespace Indexes;
using namespace std;
using namespace ColorController;
using namespace MousePos;
using namespace figureData;


// This function is called whenever a "Normal" key press is received.
void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // Escape key
        exit(0);
        break;
    case 'r':
        isSpin = isSpin ? false : true;
        break;
    case 'c':
        // add code to change color here
        isDynColor = isDynColor ? false : true;
        break;
    default:
        cout << "Unhandled key press " << key << "." << endl;
    }

    // this will refresh the screen so that the user sees the color change
    glutPostRedisplay();
}

// This function is called whenever a "Special" key press is received.
// Right now, it's handling the arrow keys.
void specialFunc(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        // add code to change light position
        lightVertPos += 0.5f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        // add code to change light position
        lightVertPos -= 0.5f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        // add code to change light position
        lightHorPos -= 0.5f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        // add code to change light position
        lightHorPos += 0.5f;
        glutPostRedisplay();
        break;
    }

    // this will refresh the screen so that the user sees the light position
    glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y)
{
    if (button==GLUT_LEFT_BUTTON)
        if (state == GLUT_UP)
        {
            float newX = x - sphereRad;
            float newY = sphereRad-y;
            float sq = sphereRad * sphereRad - newX * newX - newY * newY;
            if (sq < 0.0)
                return glutPostRedisplay();
            float newZ = sqrt(sq);

            float endUX = newY * oldZ - newZ * oldY;
            float endUY = newZ * oldX - newX * oldZ;
            float endUZ = newX * oldY - newY * oldX;
            float endAngle = asin(sqrt(endUX * endUX + endUY * endUY + endUZ * endUZ) / (sphereRad * sphereRad)) * 180.0f / pi;
            cout << "endUX: " << endUX << " endUY: " << endUY << " endUZ: " << endUZ << " angle: " << endAngle << endl;
            glMatrixMode(GL_MODELVIEW);
            glLoadMatrixf(CT);
            glRotated(endAngle, endUX, endUY, endUZ);
            glGetFloatv(GL_MODELVIEW_MATRIX, CT);
            oldX = -1.0f;
            mouseAngle = 0.0f;
            uX = 0.0f;
            uY = 0.0f;
            uZ = 0.0f;
            glutPostRedisplay();
        }
        else if (state==GLUT_DOWN)
        {
            oldX = x-sphereRad;
            oldY = sphereRad-y;
            oldZ = sqrt(sphereRad*sphereRad-oldX*oldX-oldY*oldY);
        }
    if (state==GLUT_UP && button == 3)
    {
        times+=0.008f;
        glutPostRedisplay();
    }
    if (state==GLUT_UP && button == 4)
    {
        times -= 0.008f;
        glutPostRedisplay();
    }
}

void mouseMove(int x, int y)
{
    if (oldX >= 0.0)
    {
        float newX = x - sphereRad;
        float newY = sphereRad-y;
        float sq = sphereRad * sphereRad - newX * newX - newY * newY;
        if (sq < 0.0)
            return glutPostRedisplay();
        float newZ = sqrt(sq);
        uX = newY * oldZ - newZ * oldY;
        uY = newZ * oldX - newX * oldZ;
        uZ = newX * oldY - newY * oldX;
        mouseAngle = asin(sqrt(uX * uX + uY * uY + uZ * uZ) / (sphereRad*sphereRad)) * 180.0f / pi;
        cout << "uX: " << uX << " uY: " << uY << " uZ: " << uZ << " angle: " << mouseAngle << endl;
        glutPostRedisplay();
   }
}