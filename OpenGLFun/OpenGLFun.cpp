// OpenGLFun.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <Windows.h>
#include "glut.h"

GLuint texture;
#pragma warning(disable: 4996)
bool loadTexture(const char* filename)
{
	unsigned char header[54];
	unsigned char* data;
	int dataPos;
	int width;
	int height;
	int imageSize;

	FILE * file = fopen(filename, "rb");
	if (!file) return false;
	if (fread(header, 1, 54, file) != 54) return false;
	if (header[0] != 'B' || header[1] != 'M') return false;

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (imageSize == 0) imageSize = width * height * 3;
	if (dataPos == 0) dataPos = 54;

	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);
	fclose(file);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return true;
}


void initGL() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
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

void drawQuad()
{
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.6f, -0.6f);
	glVertex2f(0.6f, -0.1f);

	glEnd();
}

void update() 
{
	glClear(GL_COLOR_BUFFER_BIT); 
	drawQuad(); // function we created to display a complete quad on the screen.
	glFlush(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutCreateWindow("GL Fun");
	glutInitWindowSize(320, 320); 
	glutInitWindowPosition(50, 50); 
	glutDisplayFunc(update); 
	initGL(); 
	loadTexture("car.bmp");
	glutMainLoop(); 
    return 0;
}

