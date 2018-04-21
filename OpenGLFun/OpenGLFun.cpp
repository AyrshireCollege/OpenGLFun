// OpenGLFun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // precompiled header created by Visual Studio
#include <Windows.h> // allows the window that renders the OpenGL content to be created
#include "glut.h" // allows the use of the OpenGL Utility Toolkit (GLUT), which simplifies the setup and use of OpenGL


void initGL() 
{
	//          ( R,    G,    B,   Alpha)
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void drawPoints() 
{
	glBegin(GL_POINTS); // a function instructing OpenGL to prepare to render items to the screen.

	glColor3f(1.0f, 1.0f, 1.0f); // sets the colour of the item that is going to be rendered. (RGB)
	
	// Each point in OpenGL is known as a vertex.
	// glVertex2F tells OpenGL to render a single point at the specified coordinates.
	// 0 means the center of the screen, and (for example) 1 means one unit from the center.
	// The settings for the camera determine exactly how far one unit from the center actually is on the screen.
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glEnd(); // a function to tell OpenGL we are finished when we are done rendering.
}

void update() 
{
	glClear(GL_COLOR_BUFFER_BIT); // resets the render buffer to the color that was specified by the glClearColor function.
	drawPoints(); // function we created to display three points on the screen.
	glFlush(); // flushes the OpenGL buffer, including the back buffer that currently holds our render.
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutCreateWindow("GL Fun"); // creates the window that will render the OpenGL content.
	glutInitWindowSize(320, 320); // initialises the size of the window.
	glutInitWindowPosition(50, 50); // sets the position of the window's upper-left corner in relation to the device's screen.
	glutDisplayFunc(update); // we need to tell GLUT the name of the function that we want to run every frame (i.e. the game loop)
	initGL(); // initialises OpenGL - we can't use it if we don't initialise it.
	glutMainLoop(); // starts the main game loop, which in turn will call our update function every frame. Basically, this starts our program.
    return 0;
}

