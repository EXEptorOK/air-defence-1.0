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
	float missileActiveMotionTime = 12.0;

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
	double missileMovingEquality(double xShift, double yShift, double x, uint8_t angleDeg, 
								 double marchAccelerationApplyPointX, unsigned short timeS, double marchAccelerationX, double marchAccelerationY) const {
		char missileState = 'u'; // u - up, d - down
		double speed = 0;
		double accelerationAngleRad = atan(marchAccelerationY / marchAccelerationX);
		double angleRad = angleDeg * (PI / 180);
		double yBallistic = 0.0;
		double startAcceleration = this->missileSpeedMPS / this->missileActiveMotionTime;
		double startLength = (startAcceleration * this->missileActiveMotionTime * this->missileActiveMotionTime) / 2;
		double startLengthX = startLength * cos(angleRad);
		double startLengthY = startLength * sin(angleRad);
		double maxHeight = (((this->missileSpeedMPS * this->missileSpeedMPS) * (sin(angleRad) * sin(angleRad)))
							/ (g_middle + (this->missileAirResistancePower / this->missileWholeMass))) + yShift;
		double accelerationLength = 0.0;
		if (tan(angleRad) - ((((g_middle + (this->missileAirResistancePower / this->missileWholeMass))
			/ (2 * this->missileSpeedMPS * this->missileSpeedMPS) * cos(angleRad) * cos(angleRad))) * (x - xShift)) > 0) {
			missileState = 'u';
		}
		else if (tan(angleRad) - ((((g_middle + (this->missileAirResistancePower / this->missileWholeMass))
					/ (2 * this->missileSpeedMPS * this->missileSpeedMPS) * cos(angleRad) * cos(angleRad) ) ) * (x - xShift)) < 0) {
			missileState = 'd';
		}
		if (x - xShift < startLengthX) {
			yBallistic = (x - xShift) * tan(angleRad) + yShift;
			return yBallistic;
		}
		x -= startLengthX;
		double arg1 = tan(angleRad) * (x - xShift);
		double arg2 = g_middle + (this->missileAirResistancePower / this->missileWholeMass);
		double arg3 = 2 * this->missileSpeedMPS * this->missileSpeedMPS * cos(angleRad) * cos(angleRad);
		double arg4 = (x - xShift) * (x - xShift);
		double arg5 = startLengthY + yShift;
		if (timeS >= 0 && marchAccelerationX != 0 && marchAccelerationY != 0) {
			if (x >= marchAccelerationApplyPointX && x <= marchAccelerationApplyPointX + (speed * timeS) + 
				(sqrt((marchAccelerationY * marchAccelerationY + marchAccelerationX * marchAccelerationX)) * timeS * timeS) / 2) {
				yBallistic = arg1 - (((arg2 - marchAccelerationY) / arg3) * arg4) + arg5;
				return yBallistic;
			}
		}
		if (x - xShift >= startLengthX) {
			yBallistic = arg1 - ((arg2 / arg3) * arg4) + arg5;
			return yBallistic;
		}
		return yBallistic;
	}
	double calculateMissileTime(uint8_t angleDeg) const {
		return (2 * this->missileSpeedMPS * sin(angleDeg * (PI / 180)) / g_middle) + this->missileActiveMotionTime;
	}
};

extern Missile aagm_9M82;
extern Missile aagm_9M83;
extern Missile aagm_MIM104A;