#pragma once

#include "Base.h"
#include "Constants.h"


class Missile
{
private:
	// missile's basical information/базовая информация о ракете
	std::string missileName;
	std::string missileCountry;
	std::string missileType;
	unsigned short missileReleaseDate;
	uint8_t missileActiveMotionTime = 12;

	// missile's cinematic characteristics/кинематические характеристики ракеты
	unsigned short missileMass;
	unsigned short missileWarheadMass;
	unsigned short missileWholeMass;
	float missileSpeedMach;
	unsigned short missileSpeedMPS;
	double missileAirResistancePower;
	double missileAirResistanceAcceleration;

	// missile's dimensions/габариты ракеты
	float missileLengthM;
	float missileDiameterMM;
public:
	Missile();

	Missile(std::string missileName, std::string missileCountry, std::string missileType, unsigned short missileReleaseDate,
		unsigned short missileWholeMass, unsigned short missileWarheadMass, float missileSpeedMach,
		double missileAirResistancePower, float missileLengthM,
		float missileDiameterMM) {

		// declaration properties
		this->missileName = missileName;
		this->missileCountry = missileCountry;
		this->missileType = missileType;
		this->missileReleaseDate = missileReleaseDate;
		this->missileWholeMass = missileWholeMass;
		this->missileWarheadMass = missileWarheadMass;
		this->missileSpeedMach = missileSpeedMach;
		this->missileAirResistancePower = missileAirResistancePower;
		this->missileLengthM = missileLengthM;
		this->missileDiameterMM = missileDiameterMM;

		// functional properties
		this->missileSpeedMPS = MachToMPS(this->missileSpeedMach);
		this->missileMass = calculateMissileMass(this->missileMass, this->missileWarheadMass);
		this->missileAirResistanceAcceleration = calculateAirResistanceAcceleration(this->missileAirResistancePower, this->missileWholeMass);
	}

	unsigned short MachToMPS(float speedMach) {
		return round(speedMach * 340);
	}

	unsigned short calculateMissileMass(unsigned short missileWholeMass, unsigned short missileWarheadMass) {
		return missileWholeMass - missileWarheadMass;
	}

	double calculateAirResistanceAcceleration(double missileAirResistancePower, unsigned short missileWholeMass) {
		return missileAirResistancePower / missileWholeMass;
	}
	double missileMovingEquality(double xShift, double yShift, double x, uint8_t angleDeg) const {
		double angleRad = angleDeg * (PI / 180);
		double yBallistic = 0.0;
		double acceleration = this->missileSpeedMPS / this->missileActiveMotionTime;
		double activeLength = (acceleration * this->missileActiveMotionTime * this->missileActiveMotionTime) / 2;
		double activeLengthX = activeLength * cos(angleRad);
		double activeLengthY = activeLength * sin(angleRad);
		if (x - xShift < activeLengthX) {
			yBallistic = (x - xShift) * tan(angleRad) + yShift;
			return yBallistic;
		}
		else if (x - xShift >= activeLengthX) {
			x -= activeLengthX;
			double arg1 = tan(angleRad) * (x - xShift);
			double arg2 = g_middle + (this->missileAirResistancePower / this->missileWholeMass);
			double arg3 = 2 * this->missileSpeedMPS * this->missileSpeedMPS * cos(angleRad) * cos(angleRad);
			double arg4 = (x - xShift) * (x - xShift);
			double arg5 = activeLengthY + yShift;
			yBallistic = arg1 - ((arg2 / arg3) * arg4) + arg5;
			return yBallistic;
		}
		return yBallistic;
	}
	double calculateMissileTime(uint8_t angleDeg) const {
		double result = (2 * this->missileSpeedMPS * sin(angleDeg * (PI / 180)) / g_middle) + 12;
		return result;
	}
};

extern Missile aagm_9M82;
extern Missile aagm_9M83;
extern Missile aagm_MIM104A;