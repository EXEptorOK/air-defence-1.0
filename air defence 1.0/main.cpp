#include <iostream>
#include <math.h>
#include <cmath>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

byte attackChoose = 1;
byte defenceChoice = 1;

class Missile 
{
private:
	// missile's basical information/базовая информация о ракете
	string missileName;
	string missileCountry;
	string missileType;
	unsigned short missileReleaseDate;

	// missile's cinematic characteristics/кинематические характеристики ракеты
	unsigned short missileMass;
	unsigned short missileWarheadMass;
	unsigned short missileWholeMass;
	float missileSpeedMach;
	unsigned short missileSpeedMPS;

	// missile's dimensions/габариты ракеты
	float missileLengthM;
	float missileDiameterMM;
public:
	Missile (string missileName, string missileCountry, string missileType, unsigned short missileReleaseDate,
			 unsigned short missileWholeMass, unsigned short missileWarheadMass, float missileSpeedMach, 
			 float missileLengthM, float missileDiameterMM) {

		// declaration properties
		this->missileName = missileName;
		this->missileCountry = missileCountry;
		this->missileType = missileType;
		this->missileReleaseDate = missileReleaseDate;
		this->missileWholeMass = missileWholeMass;
		this->missileWarheadMass = missileWarheadMass;
		this->missileSpeedMach = missileSpeedMach;
		this->missileLengthM = missileLengthM;
		this->missileDiameterMM = missileDiameterMM;

		// functional properties
		this->missileSpeedMPS = MachToMPS(this->missileSpeedMach);
		this->missileMass = calculateMissileMass(this->missileMass, this->missileWarheadMass);
	}
	Missile() {

		// declarative properties
		this->missileName = "";
		this->missileCountry = "";
		this->missileType = "";
		this->missileReleaseDate = 0;
		this->missileMass = 0;
		this->missileWarheadMass = 0;
		this->missileSpeedMach = 0;
		this->missileLengthM = 0;
		this->missileDiameterMM = 0;

		// functional properties
		this->missileSpeedMPS = 0;
		this->missileWholeMass = 0;
	}
	unsigned short MachToMPS(float speedMach) {
		return round(speedMach * 340);
	}
	unsigned short calculateMissileMass(unsigned short missileWholeMass, unsigned short missileWarheadMass) {
		return missileWholeMass - missileWarheadMass;
	}
};


class AirDefenceSystem //air defence system / система ПВО
{
private:
	string type;
	string model;
	string country;
	unsigned short releaseDate;
	unsigned maxDistance;
	unsigned maxHeight;
	vector<unsigned> startPoint;
	vector<unsigned> targetPoint;
	byte ammo;
	byte maxTargets;
	unsigned short maxTargetSpeedMPS;
	unsigned maxDetectDistance;
	float breakBetweenStartsS;
	float readyTimeS;
	const byte activeMotionTime = 12;
	Missile equipedMissile;
public:
	AirDefenceSystem() {
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

		// functional properties
		this->type = "";
		this->startPoint = { 0,0 };
		this->targetPoint = { 0,0 };
	}
	AirDefenceSystem(string model, string country, unsigned short releaseDate, unsigned maxDistance,
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
		this->equipedMissile = equipedMissile;

		// functional properties
		this->type = this->selectType(1);
		this->startPoint = this->setStartPoint();
		this->targetPoint = this->setTargetPoint();
	}
	unsigned calculateMoving(unsigned startPoint[2], unsigned targetPoint[2], unsigned short maxOwnSpeed,
							 unsigned short maxHeight) {

	}
	vector<unsigned> setStartPoint() {
		vector<unsigned> coords = { 0,0 };
		cout << "Enter start point [x,y]" << endl;
		cin >> coords[0];
		cin >> coords[1];
		cout << "Data accepted." << endl;
		return coords;
	}
	vector<unsigned> setTargetPoint() {
		vector<unsigned> coords = { 0,0 };
		cout << "Enter target point [x,y]" << endl;
		cin >> coords[0];
		cin >> coords[1];
		cout << "Data accepted." << endl;
		return coords;
	}
	string selectType(byte choice) {
		switch (choice)
		{
		case 1:
			return "ЗРК";
		case 2:
			return "ЗРПК";
		default:
			cout << "Введите корректный тип системы ПВО" << endl;
			return "UNDEFINED!";
		}
	}
};
// closer parameter hint: {ads:-> model, country, releaseDate, maxDistance, maxHeight, ammo, maxTargets, 
// maxTargetSpeedMPS, maxDetectDistance, breakBetweenStartsS, readyTimeS, equipedMissile}
// missile:-> {missileName[32], missileCountry[32],missileType[32],missileReleaseDate, missileWholeMass, 
// missileWarheadMass, missileSpeedMach, missileLengthM, missileDiameterMM}

//MISSILES: aagm - anti-aircraft guided missile 


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

	byte missileChoice = NULL;
	unsigned developerCode = 61027260;
	unsigned userCode;

	unsigned enemyLaunchCode = 23872;
	unsigned defenceLaunchCode = 56897;

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
		goto simulationStartPoint;
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
	cout << "\t1. ВСЕ, ЗДЕСЬ ПРОИСХОДЯЩЕЕ, ЯВЛЯЕТСЯ ВЫДУМАННЫМ, ВСЕ СОВПАДЕНИЯ СЛУЧАЙНЫ!!!\n\t\
			 2. ЗАПУСКАЯ ДАННОЕ ПО, ВЫ СОГЛАШАЕТЕСЬ СО ВСЕМИ РИСКАМИ И НЕСЕТЕ ЗА СЕБЯ ВСЮ ОТВЕТСВЕННОСТЬ И ПОСЛЕДСТВИЯ В ПОЛНОМ ОБЪЕМЕ!!!\n\t\
			 3. НАЖИМАЯ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ, ВЫ ПРИНИМАЕТЕ ВСЕ ВЫШЕИЗЛОЖЕННЫЕ УСЛОВИЯ, В СЛУЧАЕ ОТКАЗА ОТ СОГЛАШЕНИЯ, НЕМЕДЛЕННО ЗАКРОЙТЕ ДАННОЕ ОКНО!!!" << endl;

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

	cout << "Руководство по горячим клавишам:\n\
			 1. Жми Ctrl+([+/-]|[MWHEEL]) для изменения масштаба.\n\
			 2. Жми F1 для запуска симуляции.\n\
			 3. Жми F2 чтобы управлять паузой.\n\
			 4. Жми F3+MWHEEL для выбора атакующей ракеты и фокусировки на ней.\n\
			 5. Жми F4+MWHEEL для выбора оборонительной ракеты и фокусировки на ней.\n\
			 6. F5 - ТРЕВОГА(РАСЧЁТ ПВО ГОТОВНОСТЬ 1, НЕОБХОДИМ КОД ЗАПУСКА)!!!!!" << endl;

	cout << "Прочитал? Y/N: " << endl;
	checkAgreement(0);
	cout << "Руководство для ввода координат:\n\
			 1. Напиши необходимые числа в целом формате.\n\
			 2. Для корректного ввода представь окно ПО как координатную плоскость с началом координат в нижнем левом углу.\n\
			 3. Каждая целая единица является пикселем на экране и равна 200(двумстам) метрам в реальном масштабе для реальной жизни.\n\
             4. Например, точка (10,2) для программы расположена удалена на 10 пикселей вправо и 2 пикселя вверх от нижнего угла окна программы на экране а в реальной жизни -  на 2000(две тысячи) метров вправо и 400(четыреста) метров соответственно." << endl;

	cout << "Готов? Y/N: ";
	checkAgreement(0);
	system("pause");
	system("cls");
	simulationStartPoint:
	cout << "Вариант вражеской системы, выбери один из: \
			 1 - потенциальный противник - ВСУ, вооруженные ЗРК C-300ВМ с ракетой 9М82,\
			 2 - потенциальный противник - ВСУ, вооруженные ЗРК С-300ВМ с ракетой 9М83. \
			 3 - потенциальный противник - ВС США, вооруженные ЗРК PAC-3 \"Patriot\" с ракетой MIM-104A.\
		     По умолчанию будет выбрано 1" << endl;

	switch (missileChoice) {
	case 1:
		break;
	case 2:
		break;
	case NULL:
		break;
	}


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
	cout << "The target coordinates are given to the attacking missile. YOUR LAUNCH CODE: " << enemyLaunchCode << endl;
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
	cin >> defenceChoice;
	cout << "Would be chosen missile system...." << endl;
	defenceChoice = 1;



	Missile aagm_9M82{ "9M82", "USSR", "anti - aircraft guided missile", 1982, 5800, 150, 5.294f, 9.913f, 1.215f };
	Missile aagm_9M83{ "9M83", "USSR", "anti - aircraft guided missile", 1983, 3500, 150, 3.529f, 7.898f, 0.915f };
	Missile aagm_MIM104A{ "MIM-104A", "USA", "anti - aircraft guided missile", 2001, 700, 91, 3.706f, 5.180f, 0.400f };


	AirDefenceSystem C300BM_with_aagm_9M82{ "С-300ВМ", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M82 };
	AirDefenceSystem C300BM_with_aagm_9M83{ "С-300ВМ", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M83 };

	AirDefenceSystem enemyADS = C300BM_with_aagm_9M82;
	AirDefenceSystem defenderADS = C300BM_with_aagm_9M83;
	Sleep(5000);
	system("pause");
	return 0;
}