#pragma once
#include "Missile.h"

class AirDefenceSystem //air defence system / ñèñòåìà ÏÂÎ
{
private:
	std::string type;
	std::string model;
	std::string country;
	unsigned short releaseDate;
	unsigned maxDistance;
	unsigned maxHeight;
	std::vector<unsigned> startPoint;
	std::vector<unsigned> targetPoint;
	byte ammo;
	byte maxTargets;
	unsigned short maxTargetSpeedMPS;
	unsigned maxDetectDistance;
	float breakBetweenStartsS;
	float readyTimeS;
	const byte activeMotionTime = 12;
	Missile equipedMissile;
public:
	AirDefenceSystem();
	AirDefenceSystem(std::string model, std::string country, unsigned short releaseDate, unsigned maxDistance,
		unsigned maxHeight, byte ammo, byte maxTargets, unsigned short maxTargetSpeedMPS,
		unsigned maxDetectDistance, float breakBetweenStartsS, float readyTimeS,
		Missile equipedMissile) {

		//declarative properties
		this->model = model;
		this->country = country;
		this->releaseDate = releaseDate;
		this->maxDistance = maxDistance;
		this->maxDistance = maxDistance;
		this->maxHeight = maxHeight;
		this->ammo = ammo;
		this->maxTargets = maxTargets;
		this->maxTargetSpeedMPS = maxTargetSpeedMPS;
		this->maxDetectDistance = maxDetectDistance;
		this->breakBetweenStartsS = breakBetweenStartsS;
		this->readyTimeS = readyTimeS;
		this->startPoint = { 0,0 };
		this->targetPoint = { 0,0 };
		this->equipedMissile = equipedMissile;

		// functional properties
		this->type = "ÇÐÊ";
	}
	void setStartPoint(double x, double y) {
		this->startPoint[0] = x;
		this->startPoint[1] = y;

	}
	void setTargetPoint(double x, double y) {
		this->startPoint[0] = x;
		this->startPoint[1] = y;
	}
	void selectType(char choice) {
		switch (choice) {
		case '1':
			this->type = "ÇÐÊ";
		case '2':
			this->type = "ÇÐÏÊ";
		case '3':
			this->type = "ÏÇÐÊ";
		default:
			this->type = "UNDEFINED";
		}
	}
};


extern AirDefenceSystem C300BM_with_aagm_9M82;
extern AirDefenceSystem C300BM_with_aagm_9M83;

extern AirDefenceSystem enemySystem;
extern AirDefenceSystem defenceSystem;