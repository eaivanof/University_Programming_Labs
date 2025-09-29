#include <iostream>
#include <iomanip>
#include <cmath>

// функции решения поставленных задач
void task_1();  
void task_2();
void task_3();

// запустить задачу с номером taskNum
void taskGo(int taskNum) {
	std::cout << " --- Задание_" << taskNum << " ---" << std::endl;
	switch (taskNum) {
		case 1: task_1(); break;
		case 2: task_2(); break;
		case 3: task_3(); break;
	}
	std::cout << std::endl;
	system("pause");
	std::cout << std::endl;
}

int main() {
	// кодировка utf8
	system("chcp 65001");
	system("cls");

	// формат вывода
	std::cout << std::fixed << std::setprecision(2);

	// запускаем задачи
	taskGo(1);
	taskGo(2);
	taskGo(3);

	return 0;
}

void task_1() {
	// входные данные
	std::cout << "введите длину (целое положительное)" << std::endl;
	int a; std::cin >> a;
	std::cout << "введите ширину (целое положительное)" << std::endl;
	int b; std::cin >> b;
	std::cout << "введите высоту (целое положительное)" << std::endl;
	int c; std::cin >> c;

	// находим длину диагонали
	double diag {sqrt(a * a + b * b + c * c)};

	// вывод
	std::cout << "Диагональ кирпича со сторономи " <<
				 a << ", " << b << " и " << c <<
				 " равна " << diag << std::endl;
}

void task_2() {
	// входные данные
	std::cout << "введите длину дороги (целое положительное)" << std::endl;
	int clong; std::cin >> clong;
	std::cout << "введите время (целое положительное)" << std::endl;
	int t; std::cin >> t;
	std::cout << "введите скорость (целое)" << std::endl;
	int v; std::cin >> v;
	
	// считаем ответ
	int ans {((v*t)%clong + clong)%clong}; 

	// вывод
	std::cout << "авто у метки " << ans << std::endl;
}

void task_3() {
	// входные данные
	std::cout << "введите чило x (вещественное)" << std::endl;
	double x; std::cin >> x;
	std::cout << "введите чило y (вещественное)" << std::endl;
	double y; std::cin >> y;
	std::cout << "введите чило z (вещественное)" << std::endl;
	double z; std::cin >> z;

	// считаем значение выражения
	double ans{log(fabs((y - sqrt(fabs(x))) * (x - y / (z + x * x / 4))))};

	// вывод
	std::cout << "значение выражения " << ans << std::endl;
}
