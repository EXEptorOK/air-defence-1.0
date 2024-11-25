#pragma once
#include "Base.h"
#include "Constants.h"
#include "Missile.h"
#include "AirDefenceSystem.h"

using namespace std;

// closer parameter hint: {ads:-> model, country, releaseDate, maxDistance, maxHeight, ammo, maxTargets, 
// maxTargetSpeedMPS, maxDetectDistance, breakBetweenStartsS, readyTimeS, equipedMissile}
// missile:-> {missileName[32], missileCountry[32],missileType[32],missileReleaseDate, missileWholeMass, 
// missileWarheadMass, missileSpeedMach, missileLengthM, missileDiameterMM}

//MISSILES: aagm - anti-aircraft guided missile 


//AirDefenceSystem C_400{};
//AirDefenceSystem Buk{};
//AirDefenceSystem Tunguska{};
//AirDefenceSystem Tor{};

unsigned a = 5000;
unsigned b = 5000;
uint8_t angle = 45;
//vector<double> buffer;

void consoleThreadFunction() {
	setlocale(LC_ALL, "rus");
	system("color 0C");
	srand(time(0));
	/*for (long i = a; i < 1000000; i += 1000) {
		y = aagm_9M82.missileMovingEquality(a, b, i, angle);
		buffer.push_back(i);
		buffer.push_back(y);
		cout << "(" << i / 1000 - a/1000 << " km from start; " << y / 1000 - b/1000 << " km above the ground)";
		if (y - b < 0) {
			cout << "fly time: " << humanizeSeconds(aagm_9M82.calculateMissileTime(45.0)) << endl;
			return buffer;
		}
		cout << endl;
	}*/

	cout << "Код входа в режим разработчика:" << endl;
	cin >> userCode;
	if (userCode == developerCode) {
		cout << "Доступ разрешен. Обход проверки" << endl;
		Sleep(600);
		cout << "Доступ разрешен. Обход проверки." << endl;
		Sleep(600);
		cout << "Доступ разрешен. Обход проверки.." << endl;
		Sleep(600);
		cout << "Доступ разрешен. Обход проверки..." << endl;
		Sleep(600);
	}
	else {
		cout << "Доступ запрещен." << endl;
		consolePreparation();
	}
	
	enemySystem.selectType(enemySystemChoice);
	defenceSystem.selectType(defenceSystemChoice);
	enemySystem.setStartPoint(a,b);
	enemySystem.setTargetPoint(a,b);
	defenceSystem.setStartPoint(a,b);
	defenceSystem.setTargetPoint(a,b);


	Sleep(5000);
	system("pause");

	//return buffer;
}

int main() {
	future<void> renderAsyncFuture = async(launch::async, renderThreadFunction);
	makeBufferFuture = async(launch::async, makeBuffer , 5000, 5000, 45);
	future<void> consoleAsyncFuture = async(launch::async, consoleThreadFunction);
	return 0;
}