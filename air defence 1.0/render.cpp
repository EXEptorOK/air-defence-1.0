#pragma once
#include "Base.h"

void reshapeWindow(void) { 
	glViewport(0, 0, window_width, window_height); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(0.0, window_width, 0.0, window_height, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW); 
}


void drawObject()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glLineWidth(4);
	//  Draw Icosahedron
	glBegin(GL_LINE_STRIP);

	//glutWireIcosahedron();
	drawTrajectory(makeBuffer(5000, 5000, 45));
	glEnd();
	glFlush();
}

void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}
void init()
{
	//  Set the frame buffer clear color to black.
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display
//  OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	drawObject();

	glutSwapBuffers();
	//  Swap contents of backward and forward frame buffers
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------

void drawTrajectory(std::vector<double> buffer) {
	for (unsigned i = 0; i < buffer.size()-1; i+=2) {
		glVertex2d(buffer[i], buffer[i+1]);
		//std::cout << "Vertex: " << i << std::endl;
	}
	//std::cout << "Buffer done!" << std::endl;
}