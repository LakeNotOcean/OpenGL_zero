#include "GL/freeglut.h"
#include <cmath>
#include "custom/face.h"
#include "custom/global.h"
#include "custom/loadFigure.h"
#include "custom/figureList.h"
#include "custom/ColorController.h"
#include "custom/KeysFunctions.h"



using namespace std;
using namespace figureData;
using namespace Indexes;
using namespace ColorController;
using namespace MousePos;
// These are convenience functions which allow us to call OpenGL 
// methods on Vec3d objects
inline void glVertex(const Vector3f &a) 
{ glVertex3fv(a); }

inline void glNormal(const Vector3f &a) 
{ glNormal3fv(a); }





// This function is responsible for displaying the object.

void Spining(int value)
{
    if (isSpin) {
        angle += 0.5f;
        if (abs(angle - maxAngle) < eps)
            angle = 0.0f;
        cout << "angle is " << angle << endl;
        glutPostRedisplay();
    }
    glutTimerFunc(40, Spining, 0);
}

void DynColor(int value)
{
    if (isDynColor)
    {
        ChangeColor();
        glutPostRedisplay();
    }
    glutTimerFunc(30, DynColor, 1);
}

// Initialize OpenGL's rendering modes
void initRendering()
{
    glEnable(GL_DEPTH_TEST);   // Depth testing must be turned on
    glEnable(GL_LIGHTING);     // Enable lighting calculations
    glEnable(GL_LIGHT0);       // Turn on light #0.
    theFigure = glGenLists(1);
    glNewList(theFigure, GL_COMPILE);
    makeList();
    glEndList();
}


void drawScene(void)
{
    cout << "DrawScense" << endl;
    glMatrixMode(GL_MODELVIEW);  // Current matrix affects objects positions
    //glLoadIdentity();          // Initialize to the identity
    glLoadMatrixf(CT);
    
    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set material properties of object

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, figureColor);

	

    glPushMatrix();
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glRotatef(mouseAngle,uX,uY,uZ);
    glScalef(times, times, times);
    glGetFloatv(GL_MODELVIEW_MATRIX, CT1);
    

	// it with code which draws the object you loaded.
    glCallList(theFigure);
    // Dump the image to the screen.
    glPopMatrix();
    glutSwapBuffers();


}


// Called when the window is resized
// w, h - width and height of the window in pixels.
void reshapeFunc(int w, int h)
{
    cout << "ReshapeFunc" << endl;
    // Always use the largest square viewport possible
    if (w > h) {
        glViewport((w - h) / 2, 0, h, h);
    } else {
        glViewport(0, (h - w) / 2, w, w);
    }

    // Set up a perspective view, with square aspect ratio
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 50 degree fov, uniform aspect ratio, near = 1, far = 100
    gluPerspective(25.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Position the camera at [0,0,6], looking at [0,0,0],
    // with [0,1,0] as the up direction.
    gluLookAt(0.0, 0.0, 6.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
    // Define specular color and shininess
    GLfloat specColor[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat shininess[] = { 100.0 };

    // Note that the specular color and shininess can stay constant
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    // Set light properties

    // Light color (RGBA)
    GLfloat Lt0diff[] = { 1.0,1.0,1.0,1.0 };
    // Light position
    GLfloat Lt0pos[] = { lightHorPos, lightVertPos, 5.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);

    glGetFloatv(GL_MODELVIEW_MATRIX, CT);

}




// Main routine.
// Set up OpenGL, define the callbacks and start the main loop
int main( int argc, char** argv )
{
    loadInput("garg.obj",vecv,vecn,vecf);

    glutInit(&argc,argv);

    // We're going to animate it, so double buffer 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    // Initial parameters for window position and size
    glutInitWindowPosition( 60, 60 );
    glutInitWindowSize( windowWidth, windowHeight );
    glutCreateWindow("Assignment 0");

    // Initialize OpenGL parameters.
    initRendering();

    // Set up callback functions for key presses
    glutKeyboardFunc(keyboardFunc); // Handles "normal" ascii symbols
    glutSpecialFunc(specialFunc);   // Handles "special" keyboard keys
    glutMouseFunc(mouseFunc);
    glutMotionFunc(mouseMove);

     // Set up the callback function for resizing windows
    glutReshapeFunc( reshapeFunc );
        

    // Call this whenever window needs redrawing
    glutDisplayFunc( drawScene );
    glutTimerFunc(40, Spining, 0);
    glutTimerFunc(500, DynColor, 1);
    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop( );

    return 0;	// This line is never reached.
}
