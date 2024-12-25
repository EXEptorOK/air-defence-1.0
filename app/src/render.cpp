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
	glLineWidth(4);
	drawTrajectory();
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

void drawTrajectory() {
	glBegin(GL_LINES);
	glVertex2d(pointMap[counter], pointMap[counter + 1]);
	glVertex2d(pointMap[counter+2], pointMap[counter + 3]);
	glEnd();
	//std::cout << "Vertex: " << i << std::endl;
	counter += 4;
	if (counter >= pointMap.size() - 5) {
		counter = 0;
		return;
	}
	Sleep(70);
}
//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------