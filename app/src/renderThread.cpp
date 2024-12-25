#pragma once
#include "Base.h"


void renderThreadFunction() {
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	//centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	std::cout << "Window created succesfully!" << std::endl;
	init();

	// Set the callback functions
	//std::cout << "init succesfully!" << std::endl;

	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glOrtho(0.0, window_width, 0.0, window_height, 0.0, 1000.0);
	glColor3f(0.0, 1.0, 1.0);
	//glutFullScreen();
	//std::cout << "Reshaped succesfully!" << std::endl;
	//glutReshapeFunc(reshapeWindow());
	//std::cout << "Screen cleaned succesfully!" << std::endl;
	glutDisplayFunc(display);
	glutIdleFunc(display);
	/*glutReshapeFunc([](int window_width,int window_height) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glOrtho(0.0, window_width, 0.0, window_height, 0.0, 1000.0);
		glColor3f(0.0, 1.0, 1.0);
		});*/
	//std::cout << "Line done!" << std::endl;
	glutMainLoop();
}