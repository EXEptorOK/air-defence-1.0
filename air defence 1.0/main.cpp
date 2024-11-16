#include <iostream>
#include <math.h>
#include <cmath>
#include <windows.h>
#include <string>
#include <vector>
#include <valarray>

using namespace std;

byte attackChoose = 1;
byte defenceChoice = 1;

const double g_middle = 9.7056;
const double g_ground = 9.8066;
const double g_50km = 9.6542;

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
	double missileAirResistancePower;
	double missileAirResistanceAcceleration;

	// missile's dimensions/габариты ракеты
	float missileLengthM;
	float missileDiameterMM;
public:

	Missile() {

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

	Missile (string missileName, string missileCountry, string missileType, unsigned short missileReleaseDate,
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
	double missileMovingEquality(double x, byte angleDeg, unsigned short maxSpeedMPS, double airResistancePower, byte activeMotionTime, const double g,unsigned mass) {
		double yBallistic = ((tan(40.0) * x) - (g + (airResistancePower / mass)) / (2 * maxSpeedMPS * maxSpeedMPS * cos(40.0) * cos(40.0) * x * x) + 7080.948308);
		return yBallistic;
		//y=tan(40)𝑥−((9,7056+(22149,7986/4685))/2((1836)^2 )((cos(40))^2 ) ) 𝑥^2+7080,948308	
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
		this->equipedMissile = Missile();

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
		this->startPoint = { 0,0 };
		this->targetPoint = { 0,0 };
		this->equipedMissile = equipedMissile;

		// functional properties
		this->type = "ЗРК";
	}
	vector<unsigned> calculateMoving() {

		return { 0 };
	}
	void setStartPoint() {
		vector<unsigned> coords = { 0,0 };
		system("cls");
		cout << "Введи координаты пуска [x,y]" << endl;
		cin >> coords[0];
		cin >> coords[1];
		cout << "Данные приняты." << endl;
		this->startPoint[0] = coords[0];
		this->startPoint[1] = coords[1];
		
	}
	void setTargetPoint() {
		vector<unsigned> coords = { 0,0 };
		system("cls");
		cout << "Введи координаты цели [x,y]" << endl;
		cin >> coords[0];
		cin >> coords[1];
		cout << "Данные приняты." << endl;
		this->startPoint[0] = coords[0];
		this->startPoint[1] = coords[1];
	}
	void selectType(byte choice) {
		switch (choice) {
		case 1:
			this->type = "ЗРК";
		case 2:
			this->type = "ЗРПК";
		case 3:
			this->type = "ПЗРК";
		default:
			this->type = "UNDEFINED";
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

Missile aagm_9M82{ "9M82", "USSR", "anti - aircraft guided missile", 1982, 5800, 150, 5.294f, 22149.7986, 9.913f, 1.215f };
Missile aagm_9M83{ "9M83", "USSR", "anti - aircraft guided missile", 1983, 3500, 150, 3.529f, 20613.14039/*fix to actual!!!*/, 7.898f, 0.915f};
Missile aagm_MIM104A{ "MIM-104A", "USA", "anti - aircraft guided missile", 2001, 700, 91, 3.706f,20613.14039/*fix to actual!!!*/, 5.180f, 0.400f};


AirDefenceSystem C300BM_with_aagm_9M82{ "С-300ВМ", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M82 };
AirDefenceSystem C300BM_with_aagm_9M83{ "С-300ВМ", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M83 };

int main() {
	setlocale(LC_ALL, "rus");
	system("color 0C");
	srand(time(0));

	byte systemChoice = NULL;
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
		//goto simulationStartPoint;
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
	cout << "1. ВСЕ, ЗДЕСЬ ПРОИСХОДЯЩЕЕ, ЯВЛЯЕТСЯ ВЫДУМАННЫМ, ВСЕ СОВПАДЕНИЯ СЛУЧАЙНЫ!!!\
			 2. ЗАПУСКАЯ ДАННОЕ ПО, ВЫ СОГЛАШАЕТЕСЬ СО ВСЕМИ РИСКАМИ И НЕСЕТЕ ЗА СЕБЯ ВСЮ ОТВЕТСВЕННОСТЬ И ПОСЛЕДСТВИЯ В ПОЛНОМ ОБЪЕМЕ!!!\
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

	cout << "Руководство по горячим клавишам:\
			 1. Жми Ctrl+([+/-]|[MWHEEL]) для изменения масштаба.\
			 2. Жми F1 для запуска симуляции.\
			 3. Жми F2 чтобы управлять паузой.\
			 4. Жми F3+MWHEEL для выбора атакующей ракеты и фокусировки на ней\
			 5. Жми F4+MWHEEL для выбора оборонительной ракеты и фокусировки на ней.\
			 6. F5 - ТРЕВОГА(РАСЧЁТ ПВО ГОТОВНОСТЬ 1, НЕОБХОДИМ КОД ЗАПУСКА)!!!!!" << endl;

	cout << "Прочитал? Y/N: " << endl;
	checkAgreement(0);
	cout << "Руководство для ввода координат:\n\
			 1. Напиши необходимые числа в целом формате.\n\
			 2. Для корректного ввода представь окно ПО как координатную плоскость с началом координат в нижнем левом углу.\n\
			 3. Каждая целая единица является пикселем на экране и равна 200(двумстам) метрам в реальном масштабе для реальной жизни.\n\
             4. Например, точка (10,2) для программы расположена удалена на 10 пикселей вправо и 2 пикселя вверх от нижнего угла окна программы на экране а в реальной жизни -  на 400(две тысячи) метров вправо и 80(четыреста) метров соответственно.Итого масштаб: 1 пиксель = 40м" << endl;

	cout << "Готов? Y/N: ";
	checkAgreement(0);
	system("pause");
	system("cls");
	//simulationStartPoint:
	cout << "Вариант вражеской системы, выбери один из: \
			 1 - потенциальный противник - ВСУ, вооруженные ЗРК C-300ВМ с ракетой 9М82,\
			 2 - потенциальный противник - ВСУ, вооруженные ЗРК С-300ВМ с ракетой 9М83. \
			 3 - потенциальный противник - ВС США, вооруженные ЗРК PAC-3 \"Patriot\" с ракетой MIM-104A.\
		     По умолчанию будет выбрано 1" << endl;
	cin >> systemChoice;
	AirDefenceSystem enemySystem{ C300BM_with_aagm_9M82 };
	if (systemChoice == 1) {
		AirDefenceSystem enemySystem{ C300BM_with_aagm_9M82 };
	}
	else if (systemChoice == 2) {
		AirDefenceSystem enemySystem{ C300BM_with_aagm_9M83 };
	}
	else if (systemChoice == 3) {
		// AirDefenceSystem enemySystem = Pac-3_Patriot;
	}
	else {
		AirDefenceSystem enemySystem{ C300BM_with_aagm_9M82 };
	}
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
	cout << "" << endl;
	enemySystem.setStartPoint();
	enemySystem.setTargetPoint();
	cout << "Введенные координаты успешно переданы в бортовой компьютер запуска системы. Запомни код пуска: " << enemyLaunchCode << endl;
	system("pause");
	clearRow();
	Sleep(1000);
	cout << "Итак, необходима защита дружественной инфрастуктуры" << endl;

	cout << "Выбери тип системы ПВО:\n\t1 - ЗРК\n\t2 - ЗРПК\n\t3 - ПЗРК" << endl;
	cout << "Будет выбрана система ПВО на базе ЗРК" << endl;
	cout << "Тип системы ПВО: \n1. С-300ВМ с ракетой 9М82 \n2. С-300ВМ с ракетой 9М83" << endl;
	AirDefenceSystem defenceSystem{ C300BM_with_aagm_9M82 };
	cin >> systemChoice;
	defenceSystem.selectType(systemChoice);
	if (systemChoice == 1) {
		AirDefenceSystem defenceSystem{ C300BM_with_aagm_9M82 };
	}
	else if (systemChoice == 2) {
		AirDefenceSystem defenceSystem{ C300BM_with_aagm_9M83 };
	}
	else {
		AirDefenceSystem defenceSystem{ C300BM_with_aagm_9M82 };
	}

	defenceSystem.setStartPoint();
	defenceSystem.setTargetPoint();


	Sleep(5000);
	system("pause");
	return 0;
}