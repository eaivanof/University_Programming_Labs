#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

// функции решения поставленных задач
void task_1();
void task_2();
void task_3();
void task_4();

// запустить задачу с номером taskNum
void taskGo(int taskNum) {
	std::cout << " --- Задание_" << taskNum << " ---" << std::endl;
	switch (taskNum) {
		case 1: task_1(); break;
		case 2: task_2(); break;
		case 3: task_3(); break;
        case 4: task_4(); break;
	}
	std::cout << std::endl;
	system("pause");
	std::cout << std::endl;
}

int main() {
    // кодировка utf8
    system("chcp 65001");
    system("cls");

    taskGo(1);
    taskGo(2);
    taskGo(3);
    taskGo(4);

    return 0;
}

void task_1() {
    // ввод данных
    std::cout << "введите четыре цифры разделённых пробелом" << std::endl;
    std::vector<int> chars(4);
    std::cin >> chars[0] >> chars[1] >> chars[2] >> chars[3];

    // можно ли составить счастливый номер
    bool isHappy{false};
    // перебор всех перестановок начиная с наименьшей
    std::sort(chars.begin(), chars.end());
    do {
        if (chars[0] + chars[1] == chars[2] + chars[3]) {
            if (!isHappy) {
                std::cout << "счастливые номера:" << std::endl;
                isHappy = true;
            }
            std::cout << chars[0] << chars[1] << chars[2] << chars[3] << std::endl;
        } 
    } while (std::next_permutation(chars.begin(), chars.end()));

    // если счастливых номеров не нашлось
    if (!isHappy) {
        std::cout << "счастливых номеров нет" << std::endl;
    }
}

void task_2() {
    // ввод данных
    std::cout << "введите число x (вещественное)" << std::endl;
    double x; std::cin >> x;
    std::cout << "введите число y (вещественное)" << std::endl;
    double y; std::cin >> y;

    // вычисляем значение выражения
    double ans;
	if ((x > 0) && (x > y)) {
        ans = (1 - log(x - y)) / (log(fabs(x - 2 * y)));
    }
	else if (x <= 0) {
        ans = exp(-y) + (2 - sin(x)) / (2 + sin(x));
    }
	else {
        ans = 1 / exp(x + y);
    }

    // вывод
    std::cout << "значение выражения: " << ans << std::endl;
}

void task_3() {
    // ввод данных
    std::cout << "введите число x (вещественное)" << std::endl;
    double x; std::cin >> x;
    std::cout << "введите число y (вещественное)" << std::endl;
    double y; std::cin >> y;
    
    // принадлежит ли точка закрашенной области
    bool isBelongs{false};
	if (x * x + y * y > 16) { // вне окружности
		if ((y < 0) && (y >= x * x - 6)) { // Q R
            isBelongs = true;
		}
	}
	else { // в окружности включая саму окружность
		if ((y >= x * x - 6) || (y < x * x - 6 && x > 0)) { // F G L M или H N
            isBelongs = true;
        }
	}

    // вывод
    if (isBelongs) {
        std::cout << "точка принадлежит закрашенной области" << std::endl;
    }
	else {
        std::cout << "точка НЕ принадлежит закрашенной области" << std::endl;
    }
}

void task_4() {
    // ввод данных
    std::cout << "введите вещественное число > 1" << std::endl;
    double x; std::cin >> x;

    const double PI = acos(-1); // число пи
    // считаем сумму 
    double sum = PI / 2, tmp = -1 / x; 
    int index = 1;
    while (fabs(tmp) >= 1e-7) {
        sum += tmp;
        tmp *= -1 * (2 * index - 1) / ((2 * index + 1) * x * x);
        ++index;
    }

    // формат вывода
    std::cout << std::fixed << std::setprecision(9);
    // вывод
    std::cout << "Полученная сумма:            " << sum << std::endl;
    std::cout << "Значение atan из библиотеки: " << atan(x) << std::endl;
}
