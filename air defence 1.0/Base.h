#pragma once

#include "Windows.h"
#include <vector>
#include <gl/freeglut.h>
#include <string>

#include <math.h>
#include <iostream>
#include <cmath>
#include <thread>
#include <future>

extern const char* window_title;

extern unsigned enemyStartX;
extern unsigned enemyStartY;
extern unsigned enemyTargetY;

extern byte systemChoice;
extern unsigned developerCode;
extern unsigned userCode;

extern unsigned enemyLaunchCode;
extern unsigned defenceLaunchCode;

extern double y;
extern std::vector<double> buffer;

extern int window_x;
extern int window_y;

//  variables representing the window size
extern int window_width;
extern int window_height;

extern int argc;
extern char** argv;


void drawObject();
void centerOnScreen();
void init();
void display(void);