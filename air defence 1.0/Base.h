#pragma once
#define PI dev_pi_number

#include "Windows.h"
#include <gl/freeglut.h>
#include <math.h>
#include <stdio.h>

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <thread>
#include <future>

#pragma comment(lib, "httpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

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
extern double missileX;

extern int window_x;
extern int window_y;
extern unsigned counter;

//  variables representing the window size
extern int window_width;
extern int window_height;
extern std::vector<double> pointMap;
extern std::future<int> makeBufferFuture;

extern int argc;
extern char** argv;

extern void drawObject();
extern void centerOnScreen();
extern void init();
extern void display(void);
extern void renderThreadFunction();
extern void reshapeWindow(void);
void drawTrajectory();

extern void consolePreparation(void);
extern void clearRow(void);
extern void checkAgreement(uint8_t code);
extern void logout(void);

std::string humanizeSeconds(long seconds);

int makeBuffer(unsigned a, unsigned b, uint8_t angle);