#pragma once
#include "Base.h"
#include "Constants.h"
#include "Missile.h"

using namespace std;

extern const double g_middle = 9.7056;
extern const double g_ground = 9.8066;
extern const double g_50km = 9.6542;
extern const double PI = 3.1415926535;

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
	void setStartPoint(double x, double y) {
		//system("cls");
		//cout << "Введи координаты пуска [x,y]" << endl;
		//cin >> enemyStartX;
		//cin >> enemyStartY;
		//cout << "Данные приняты." << endl;
		this->startPoint[0] = x;
		this->startPoint[1] = y;
		
	}
	void setTargetPoint(double x, double y) {
		//system("cls");
		//cout << "Введи координаты цели [x,y]" << endl;
		//cin >> coords[0];
		//cin >> coords[1];
		//cout << "Данные приняты." << endl;
		this->startPoint[0] = x;
		this->startPoint[1] = y;
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

static void clearRow() {
	cout << "\r                                                                                            \r";
}

static void checkAgreement(uint8_t code) {
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

string humanizeSeconds(long seconds) {
	string time;
	if (seconds < 36000) {
		time += '0';
	}
	time += to_string(floor(seconds / 3600));
	time += "H:";
	if (seconds % 3600 < 600) {
		time += '0';
	}
	time += to_string(floor((seconds % 3600) / 60));
	time += "M:";
	if ((seconds % 3600) % 60 < 10) {
		time += '0';
	}
	time += to_string(floor((seconds % 3600) % 60)) + 'S';
	time.replace(3, 7, "");
	time.replace(6, 7, "");
	time.replace(9, 7, "");
	return time;
}

Missile aagm_9M82{ "9M82", "USSR", "anti - aircraft guided missile", 1982, 5800, 150, 5.294f, 30000.0, 9.913f, 1.215f };
Missile aagm_9M83{ "9M83", "USSR", "anti - aircraft guided missile", 1983, 3500, 150, 3.529f, 20613.14039/*fix to actual!!!*/, 7.898f, 0.915f};
Missile aagm_MIM104A{ "MIM-104A", "USA", "anti - aircraft guided missile", 2001, 700, 91, 3.706f,20613.14039/*fix to actual!!!*/, 5.180f, 0.400f};


AirDefenceSystem C300BM_with_aagm_9M82{ "С-300ВМ", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M82 };
AirDefenceSystem C300BM_with_aagm_9M83{ "С-300ВМ", "USSR", 1983, 40000, 30000,  48, 16, 4500, 250, 1.5f, 7.5f, aagm_9M83 };

AirDefenceSystem enemySystem{ C300BM_with_aagm_9M82 };
AirDefenceSystem defenceSystem{ C300BM_with_aagm_9M82 };

unsigned a = 5000;
unsigned b = 5000;
uint8_t angle = 45;

vector<double> consoleThreadFunction() {
	setlocale(LC_ALL, "rus");
	system("color 0C");
	srand(time(0));
	for (long i = a; i < 1000000; i += 1000) {
		y = aagm_9M82.missileMovingEquality(a, b, i, angle);
		buffer.push_back(i);
		buffer.push_back(y);
		cout << "(" << i / 1000 - a/1000 << " km from start; " << y / 1000 - b/1000 << " km above the ground)";
		if (y - b < 0) {
			cout << "fly time: " << humanizeSeconds(aagm_9M82.calculateMissileTime(45)) << endl;
			return buffer;
		}
		cout << endl;
	}

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
	enemySystem.setStartPoint(a,b);
	enemySystem.setTargetPoint(a,b);
	cout << "Введенные координаты успешно переданы в бортовой компьютер запуска системы. Запомни код пуска: " << enemyLaunchCode << endl;
	system("pause");
	clearRow();
	Sleep(1000);
	cout << "Итак, необходима защита дружественной инфрастуктуры" << endl;

	cout << "Выбери тип системы ПВО:\n\t1 - ЗРК\n\t2 - ЗРПК\n\t3 - ПЗРК" << endl;
	cout << "Будет выбрана система ПВО на базе ЗРК" << endl;
	cout << "Тип системы ПВО: \n1. С-300ВМ с ракетой 9М82 \n2. С-300ВМ с ракетой 9М83" << endl;

	cin >> systemChoice;
	defenceSystem.selectType(systemChoice);

	defenceSystem.setStartPoint(a,b);
	defenceSystem.setTargetPoint(a,b);


	Sleep(5000);
	system("pause");

	return buffer;
}

static void renderThreadFunction() {
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	init();

	// Set the callback functions
	glutDisplayFunc(display);

	glutMainLoop();
}

future<vector<double>> consoleAsyncFuture;
static void logout() {
	vector<double> pointMap{ consoleAsyncFuture.get() };
	cout << pointMap[345];
}

int main() {
	consoleAsyncFuture = async(launch::async, consoleThreadFunction);
	future<void> renderAsyncFuture = async(launch::async, renderThreadFunction);
	future<void> logAsyncFuture = async(launch::async, logout);
	return 0;
}