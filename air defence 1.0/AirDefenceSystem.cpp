#include "AirDefenceSystem.h"

AirDefenceSystem::AirDefenceSystem() {
	this->model = "";
	this->country = "";
	this->releaseDate = 0;
	this->maxDistance = 0;
	this->maxDistance = 0;
	this->maxHeight = 0;
	this->ammo = 0;
	this->maxTargets = 0;
	this->maxTargetSpeedMPS = 0;
	this->maxDetectDistance = 0;
	this->breakBetweenStartsS = 0.0f;
	this->readyTimeS = 0.0f;
	this->equipedMissile = Missile();

	// functional properties
	this->type = "";
	this->startPoint = { 0,0 };
	this->targetPoint = { 0,0 };
}


AirDefenceSystem C300BM_with_aagm_9M82{ "я-300бл", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M82 };
AirDefenceSystem C300BM_with_aagm_9M83{ "я-300бл", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M83 };

AirDefenceSystem enemySystem{ C300BM_with_aagm_9M82 };
AirDefenceSystem defenceSystem{ C300BM_with_aagm_9M82 };