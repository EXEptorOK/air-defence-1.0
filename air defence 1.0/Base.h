#pragma once
#define PI dev_pi_number

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

extern byte enemySystemChoice;
extern byte defenceSystemChoice;

extern unsigned developerCode;
extern unsigned userCode;

extern unsigned enemyLaunchCode;
extern unsigned defenceLaunchCode;

extern double y;

extern int window_x;
extern int window_y;

//  variables representing the window size
extern int window_width;
extern int window_height;

extern int argc;
extern char** argv;

extern void drawObject();
extern void centerOnScreen();
extern void init();
extern void display(void);
extern void renderThreadFunction();
extern void reshapeWindow(void);
extern void drawTrajectory(std::vector<double> buffer);

extern void consolePreparation(void);
extern void clearRow(void);
extern void checkAgreement(uint8_t code);

std::string humanizeSeconds(long seconds);

std::vector<double> makeBuffer(unsigned a, unsigned b, uint8_t angle);