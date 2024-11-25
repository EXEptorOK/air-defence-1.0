#pragma once
#include "Base.h"
#include "Missile.h"
#include "AirDefenceSystem.h"

using namespace std;

const char* window_title = "MISSILE LAUNCHER";

unsigned enemyStartX = 0;
unsigned enemyStartY = 0;
unsigned enemyTargetY = 0;

byte enemySystemChoice = NULL;
byte defenceSystemChoice = NULL;
unsigned developerCode = 61027260;
unsigned userCode;

unsigned enemyLaunchCode = 23872;
unsigned defenceLaunchCode = 56897;

double y;

int window_x;
int window_y;

//  variables representing the window size
int window_width = 600;
int window_height = 400;
std::vector<double> pointMap = makeBuffer(5000, 5000, 45);

int argc;
char** argv;
std::future<std::vector<double>> makeBufferFuture;

void clearRow() {
	cout << "\r                                                                                            \r";
}

void checkAgreement(uint8_t code) {
	char agreement;
	cin >> agreement;
	if (agreement == 'y' || agreement == 'Y') {
		system("cls");
	}
	else if ((agreement == 'N' || agreement == 'n') && code == 0) {
		cout << "Read carefully and then continue" << endl;
		system("pause");
		system("cls");
	}
	else if ((agreement == 'N' || agreement == 'n') && code == 1) {
		cout << code;
		system("exit");
	}
	else {
		cout << "Type the answer correctly!!!" << endl;
		checkAgreement(code);
	}
}

void logout() {
	pointMap.clear();
	pointMap = { makeBufferFuture.get() };
	cout << pointMap[345] << endl;
}

string humanizeSeconds(long seconds) {
	string time;
	if (seconds < 36000) {
		time += '0';
	}
	time += to_string(floor(seconds / 3600));
	time += "H:";
	if (seconds % 3600 < 600) {
		time += '0';
	}
	time += to_string(floor((seconds % 3600) / 60));
	time += "M:";
	if ((seconds % 3600) % 60 < 10) {
		time += '0';
	}
	time += to_string(floor((seconds % 3600) % 60)) + 'S';
	time.replace(3, 7, "");
	time.replace(6, 7, "");
	time.replace(9, 7, "");
	return time;
}

vector<double> makeBuffer(unsigned a, unsigned b, uint8_t angle) {
	vector<double> buffer;
	for (long i = a; i < 2000000; i += 1000) {
		y = aagm_9M82.missileMovingEquality(a, b, i, angle);
		buffer.push_back(i/410);
		buffer.push_back(y/410);
		if (y - b < 0) {
			return buffer;
		}
	}
	return buffer;
}