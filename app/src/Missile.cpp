#pragma once
#include "include/Missile.h"
#include "include/Base.h"

Missile::Missile() {

	// declarative properties
	this->missileName = "";
	this->missileCountry = "";
	this->missileType = "";
	this->missileReleaseDate = 0;
	this->missileMass = 0;
	this->missileWarheadMass = 0;
	this->missileSpeedMach = 0;
	this->missileAirResistancePower = 0.0;
	this->missileLengthM = 0;
	this->missileDiameterMM = 0;

	// functional properties
	this->missileSpeedMPS = 0;
	this->missileWholeMass = 0;
	this->missileAirResistanceAcceleration = 0.0;
}

Missile aagm_9M82{ "9M82", "USSR", "anti - aircraft guided missile", 1982, 5800, 150, 5.294f, 30000.0, 9.913f, 1.215f };
Missile aagm_9M83{ "9M83", "USSR", "anti - aircraft guided missile", 1983, 3500, 150, 3.529f, 20613.14039/*fix to actual!!!*/, 7.898f, 0.915f };
Missile aagm_MIM104A{ "MIM-104A", "USA", "anti - aircraft guided missile", 2001, 700, 91, 3.706f,20613.14039/*fix to actual!!!*/, 5.180f, 0.400f };
