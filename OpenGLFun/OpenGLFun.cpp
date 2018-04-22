// OpenGLFun.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <Windows.h>
#include "glut.h"


void initGL() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void drawPoints() 
{
	glBegin(GL_POINTS);

	glColor3f(1.0f, 1.0f, 1.0f);
	
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glEnd();
}

void drawLines()
{
	glBegin(GL_LINES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);

	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glEnd();
}

void drawSolidTriangle()
{
	glBegin(GL_TRIANGLES);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glEnd();
}

void drawGradientTriangle()
{
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, -0.6f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.7f, -0.6f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.4f, -0.1f);

	glEnd();
}

void update() 
{
	glClear(GL_COLOR_BUFFER_BIT); 
	drawGradientTriangle(); // function we created to display a complete triangle on the screen.
	glFlush(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutCreateWindow("GL Fun");
	glutInitWindowSize(320, 320); 
	glutInitWindowPosition(50, 50); 
	glutDisplayFunc(update); 
	initGL(); 
	glutMainLoop(); 
    return 0;
}

