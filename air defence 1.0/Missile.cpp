#pragma once
#include "Missile.h"
#include "Base.h"

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


