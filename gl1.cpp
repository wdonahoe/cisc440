// OpenGL1.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <iostream>

#include <sys/types.h>
#include <GL/freeglut.h>

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif
typedef struct {
	double l, r, b, t;
} Extent;
Extent world = {-1, 1, -1, 1};
GLint viewport[4];
using namespace std;

/**
   Read an arbitrary image file using the ImageMagick library, and put the
   image data into a global array. filename is the path to the file
   returns 0 on sucessful read.
*/

// Global variables:
void display2()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0, 0.8, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(-0.5, -0.5);
	glVertex2d( 0.5, -0.5);
	glVertex2d( 0.5,  0.5);
		
	glEnd();
	glFlush();
	glutSwapBuffers();

}
void display1()
{
	glClearColor(0, 0, 0, 1);
    glClear( GL_COLOR_BUFFER_BIT );
	glColor3d(0, 0.8, 1.0);
	glBegin(GL_POLYGON);
		glVertex2d(-0.5, -0.5);
		glVertex2d( 0.5, -0.5);
		glVertex2d( 0.5,  0.5);
		glVertex2d(-0.5,  0.5);
	glEnd();
	glFlush();
	glutSwapBuffers();
}
void display3()
{
	float delta = 4;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0, 0.8, 1.0);
	double angle = 0;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 90; i++) {
		glVertex2d(cos(angle*PI/180.0),sin(angle*PI/180.0));
	    angle += delta;
	}
	glEnd();
	glFlush();
	glutSwapBuffers();

}

void display4()
{
	double rInner = 0.3, rOuter = 1.0, rOffset = 0.2;
	double angle = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    for (int i = 0; i < 36000; i++) {
        glPushMatrix();
        glRotated(angle, 0, 0, 1.0);
        glTranslated(rOuter - rInner, 0, 0);
        glRotated(-angle*rOuter/rInner,0,0,1);
        glBegin(GL_POINTS);
        glVertex2d(rOffset, 0);
        glEnd();
        glPopMatrix();
        angle += 1.0;
    }
    glFlush();
	glutSwapBuffers();
}

void display5()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0, 0.8, 1.0);
	glutWireTeapot(0.5);
    glFlush();
    glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

int main( int argc, char *argv[] ) {
    // initialize image magic:
    // create instance of an ImageWindow (global variable)

    // window size parameters
    int w = 256; int h = 256;

    // glut initialization functions:
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize(w,h);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Your World");

    // display, onMouseButton, mouse_motion, onKeyPress, and resize are functions defined above
    glutDisplayFunc(display1);       
    //glutMouseFunc(onMouseButton);
    //glutPassiveMotionFunc( mouse_motion );
    //glutKeyboardFunc(onKeyPress);
    glutReshapeFunc(resize);

    // start glutMainLoop -- infinite loop
    glutMainLoop();
    return 0;
}