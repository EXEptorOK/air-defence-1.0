#include <iostream>
#include <math.h>
#include <cmath>
#include <windows.h>
#include <string>

using namespace std;

byte attackChoose;
byte defenceChoose;

class Missile 
{
private:
	// missile's basical information/базовая информация о ракете
	char missileName[32];
	char missileCountry[32];
	char missileType[32];
	unsigned short missileReleaseDate;

	// missile's cinematic characteristics/кинематические характеристики ракеты
	unsigned short missileMass;
	unsigned short missileWarheadMass;
	unsigned short missileWholeMass;
	float missileSpeedMach;
	unsigned short missileSpeedMPS;

	// missile's dimensions/габариты ракеты
	float missileLengthM;
	unsigned short missileDiameterMM;
public:
	Missile (char missileName[32], char missileCountry[32], char missileType[32], unsigned short missileReleaseDate,
			 unsigned short missileMass, unsigned short missileWarheadMass,
			 float missileSpeedMach, float missileLengthM, unsigned short missileDiameterMM) {

		// declaration properties
		this->missileName[32] = missileName[32];
		this->missileCountry[32] = missileCountry[32];
		this->missileType[32] = missileType[32];
		this->missileReleaseDate = missileReleaseDate;
		this->missileMass = missileMass;
		this->missileWarheadMass = missileWarheadMass;
		this->missileSpeedMach = missileSpeedMach;
		this->missileLengthM = missileLengthM;
		this->missileDiameterMM = missileDiameterMM;

		// functional properties
		this->missileSpeedMPS = MachToMPS(this->missileSpeedMach);
		this->missileWholeMass = calculateWholeMass(this->missileMass, this->missileWarheadMass);
	}
	unsigned short MachToMPS(float speedMach) {
		return round(speedMach * 340);
	}
	unsigned short calculateWholeMass(unsigned short missileMass, unsigned short warheadMass) {
		return missileMass + warheadMass;
	}
};

class AirDefenceSystem: public Missile //air defence system / система ПВО
{
private:
	string type;
	string model;
	string country;
	unsigned short releaseDate;
	unsigned short maxDistance;
	unsigned short maxHeight;
	unsigned startPoint[2];
	unsigned targetPoint[2];
	byte ammo;
	byte maxTargets;
	unsigned short maxTargetSpeedMPS;
	unsigned short maxDetectDistance;
	float breakBetweenStartsS;
	byte readyTimeS;
	const byte activeMotionTime = 12;
public:
	AirDefenceSystem(/*ads:->*/string type, string model, string country, unsigned short releaseDate,
					 unsigned short maxDistance, unsigned short maxHeight, unsigned startPoint[2],
					 unsigned targetPoint[2], byte ammo, byte maxTargets, 
					 unsigned short maxTargetSpeedMPS, unsigned short maxDetectDistance,
					 float breakBetweenStartsS, byte readyTimeS, /*missile:->*/
					 char missileName[32], char missileCountry[32], char missileType[32],
					 unsigned short missileReleaseDate, unsigned short missileMass, unsigned short missileWarheadMass,
					 float missileSpeedMach, float missileLengthM, unsigned short missileDiameterMM) : Missile (
					 missileName, missileCountry, missileType, missileReleaseDate,
					 missileMass, missileWarheadMass, missileSpeedMach, missileLengthM,
				     missileDiameterMM) {

		this->type = type;
		this->model = model;
		this->country = country;
		this->releaseDate = releaseDate;
		this->maxDistance = maxDistance;
		this->maxDistance = maxDistance;
		this->maxHeight = maxHeight;
		this->startPoint[2] = startPoint[2];
		this->targetPoint[2] = targetPoint[2];
		this->ammo = ammo;
		this->maxTargets = maxTargets;
		this->maxTargetSpeedMPS = maxTargetSpeedMPS;
		this->maxDetectDistance = maxDetectDistance;
		this->breakBetweenStartsS = breakBetweenStartsS;
		this->readyTimeS = readyTimeS;
	}
	unsigned calculateMoving(unsigned startPoint[2], unsigned targetPoint[2], unsigned short maxOwnSpeed,
							 unsigned short maxHeight) {

	}
	void selectType(byte choice) {
		switch (choice)
		{
		case 1:
			type = "ЗРК";
			break;
		case 2:
			type = "ЗРПК";
		default:
			type = "UNDEFINED!";
			cout << "Введите корректный тип системы ПВО";
		}
	}
};

//AirDefenceSystem C_300V4{};
//AirDefenceSystem C_400{};
//AirDefenceSystem Buk{};
//AirDefenceSystem Tunguska{};
//AirDefenceSystem Tor{};

//AirDefenceSystem Pac3_Patriot{};

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


int main() {
	setlocale(LC_ALL, "rus");
	system("color 0C");
	srand(time(0));

	unsigned int developerCode = 61027260;
	unsigned int userCode;
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
		goto goToSimulation;
	}
	else {
		cout << "Доступ запрещен." << endl;
	}
	cout << "    __  __ ___ ____ ____ ___ _     _____     ____    _    _   _ ____  ____   _____  __ " << endl;
	cout << "   |  \\/  |_ _/ ___/ ___|_ _| |   | ____|   / ___|  / \\  | \\ | |  _ \\| __ ) / _ \\ \\/ / " << endl;
	cout << "   | |\\/| || |\\___ \\___ \\| || |   |  _| ____\\___ \\ / _ \\ |  \\| | | | |  _ \\| | | \\  /  " << endl;
	cout << "   | |  | || | ___) |__) | || |___| |__|_____|__) / ___ \\| |\\  | |_| | |_) | |_| /  \\  " << endl;
	cout << "   |_|  |_|___|____/____/___|_____|_____|   |____/_/   \\_\\_| \\_|____/|____/ \\___/_/\\_\\ " << endl;
	cout << "                                                                                       " << endl;

	cout << endl << "\nДобро пожаловать в симулятор ПВО Missile-Launcher 0.1 Beta!(версия оффлайн, 2D, одиночная игра)" << endl;
	cout << "\t1. ВСЕ, ЗДЕСЬ ПРОИСХОДЯЩЕЕ, ЯВЛЯЕТСЯ ВЫДУМАННЫМ, ВСЕ СОВПАДЕНИЯ СЛУЧАЙНЫ!!!\n\t2. ЗАПУСКАЯ ДАННОЕ ПО, ВЫ СОГЛАШАЕТЕСЬ СО ВСЕМИ РИСКАМИ И НЕСЕТЕ ЗА СЕБЯ ВСЮ ОТВЕТСВЕННОСТЬ И ПОСЛЕДСТВИЯ В ПОЛНОМ ОБЪЕМЕ!!!\n\t3. НАЖИМАЯ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ, ВЫ ПРИНИМАЕТЕ ВСЕ ВЫШЕИЗЛОЖЕННЫЕ УСЛОВИЯ, В СЛУЧАЕ ОТКАЗА ОТ СОГЛАШЕНИЯ, НЕМЕДЛЕННО ЗАКРОЙТЕ ДАННОЕ ОКНО!!!" << endl;
	cout << "Вы принимате условия? Y/N:" << endl;
	checkAgreement(1);
	Sleep(400);
	cout << "Загрузка";
	Sleep(600);
	clearRow();
	cout << "Загрузка.";
	Sleep(600);
	clearRow();
	cout << "Загрузка..";
	Sleep(600);
	clearRow();
	cout << "Загрузка..." << endl;
	Sleep(1000);
	cout << "Загрузка успешно завершена!" << endl;
	Sleep(700);

	cout << "Here is a supply to hotkeys:\n1. Use Ctrl+([+/-]|[MWHEEL]) to change the scale.\n2. Use F1 to start the simulation.\n3. Use F2 to toggle pause.\n4. Use F3 to focus on attacking missile.\n5. Use F4 to focus on defence missile. 6. F5 - ALARM(IMMMEDIATE LAUNCH OF AIR-DEFENCE SYSTEM)!!!!!" << endl;
	cout << "Have you read? Y/N: " << endl;
	checkAgreement(0);
	cout << "Here is a supply to enter required coordinates:\n1. Type your numbers in integer number formate.\n2. Imagine the coordinate field, where Point(0,0) - is a left-down corner of console.\n3. Every integer means pixel of console and 200 meters with default scale in real life.\n4. For example, point (10,2) placed in 2000 meters right and 400 meters up from left screen'corner." << endl;
	cout << "Ready? Y/N: ";
	checkAgreement(0);
	system("pause");
	system("cls");
	cout << "Type of attacking system: ballistic missile" << endl;
	cout << "Enter coordinates of threat" << endl;
	cout << "X ->(horizontal): ";
	cin >> point_ams[0];
	cout << "Y ^(vertical): ";
	cin >> point_ams[1];

	cout << "Loading";
	Sleep(600);
	clearRow();
	cout << "Loading.";
	Sleep(600);
	clearRow();
	cout << "Loading..";
	Sleep(600);
	clearRow();
	cout << "Loading..." << endl;
	Sleep(1000);
	cout << "The target coordinates are given to the attacking missile. YOUR LAUNCH CODE: 23872" << endl;
	cout << "Any changes? Y/N: " << endl;
	system("pause");
	system("cls");
	clearRow();
	cout << "Sure? Y/N: " << endl;
	checkAgreement(0);
	system("pause");
	clearRow();
	Sleep(1000);
	cout << "Roger that. So let us try to defend this threat..." << endl;

	cout << "Choose the type of anti-aircraft system:\n\t1 - missile system\n\t2 - machine gun system" << endl;
	cin >> defenceChoose;
	cout << "Would be chosen missile system...." << endl;
	defenceChoose = 1;


	goToSimulation:
	Sleep(5000);
	system("pause");
	return 0;
}

//reserve pieces


//switch (defenceChoose)
//{
//case 1:
//	type = "ЗРК";
//	break;
//case 2:
//	type = "ЗРПК";
//default:
//	type = "UNDEFINED!";
//	cout << "Введите корректный тип системы ПВО";
//}
//model = ads_model;
//country = ads_country;
//releaseDate = ads_releaseDate;
//maxDistance = ads_maxDistance;
//maxHeight = ads_maxHeight;
//ammo = ads_ammo;
//maxTargets = ads_maxTargets;
//maxTargetSpeedMPS = ads_maxTargetSpeedMPS;
//maxDetectDistance = ads_maxDetectDistance;
//breakBetweenStartsS = ads_breakBetweeenStartsS;
//readyTimeS = ads_readyTimeS;
//equipedMissile = ads_equipedMissile;