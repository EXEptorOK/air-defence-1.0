#pragma once
#include "Base.h"

const char* window_title = "MISSILE LAUNCHER";

unsigned enemyStartX = 0;
unsigned enemyStartY = 0;
unsigned enemyTargetY = 0;

byte systemChoice = NULL;
unsigned developerCode = 61027260;
unsigned userCode;

unsigned enemyLaunchCode = 23872;
unsigned defenceLaunchCode = 56897;

double y;
std::vector<double> buffer;

int window_x;
int window_y;

//  variables representing the window size
int window_width = 480;
int window_height = 480;

int argc;
char** argv;


void drawObject()
{
	//  Draw Icosahedron
	glutWireIcosahedron();
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
void display()
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear(GL_COLOR_BUFFER_BIT);

	//  Draw object
	drawObject();

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
