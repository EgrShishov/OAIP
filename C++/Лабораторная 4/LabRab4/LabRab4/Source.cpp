#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
bool checkinput(int* k) {
	int scan = scanf_s("%d", k);
	if (scan != 1) {
		return false;
	}
	int count = 0;
	char temp = 0;
	while ((temp = getchar()) != '\n') {
		if ((temp > '9') || (temp < '0') && (temp != ' ') && (temp != '.')) {
			return false;
		}
		if (temp == '.') {
			continue;
		}
		else {
			if (temp == '0') {
				continue;
			}
			else {
				return false;
			}
			continue;
		}
	}
	return true;
}
bool arrcheckinput(int* k) {
	int scan = scanf_s("%d", k);
	char temp = 0;

	while ((temp = getchar()) != '\n') {
		if ((temp > '9') || (temp < '0') && (temp != ' ') && (temp != '.')) {
			return false;
		}
		if (temp == '.') {
			continue;
		}
		else {
			if (temp == '0') {
				continue;
			}
			else {
				return false;
			}
			continue;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "ru");
	system("color 0A");
	char answer;
	do {
		system("cls");
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Задача 1.\n\nВариант 10.\n\nОпределить симметричен ли статический массив из k элементов.\n\nВыполнил Шишов Егор.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Введите количество элементов \n";
		int k; int i; bool g;
		/*while (true)
		{
			std::cin >> k;
			if (std::cin.fail()) // извлечение не производилось
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "ошибка,попробуйте еще раз\n";
				continue;
			}
			// очищаем любой дополнительный ввод из потока
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "ошибка,попробуйте еще раз\n";
				continue;
			}

			if (k <= 0)
			{
				std::cout << "ошибка\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&k) || k <1) {
			std::cout << "Ошибка ввода\n";
			rewind(stdin);
		}
		int a[100];
		std::cout << "Введите массив через Enter \n";
		//while (true) {
		//	for (int i = 0; i < k; i++) {
		//		std::cin >> a[i];
		//		if (std::cin.fail()) // извлечение не производилось
		//		{
		//			std::cin.clear();
		//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//			std::cout << "ошибка,введите заново с " << i + 1 << "-го элемента\n";
		//			std::cin >> a[i];
		//			continue;
		//		}
		//	}
		//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//	if (std::cin.gcount() > 1)
		//	{
		//		std::cout << "превышено количество элементов\n";
		//		continue;
		//	}
		//	break;
		//}
		for (int i = 0; i < k; i++) {
			while (!arrcheckinput(&a[i])) {
		    std::cout << "Введите элемент a[" << i + 1 << "] элемент заново\n";
			rewind(stdin);
			}
		}

		for (i = 0; i < k; i++) {
			if (a[i] == a[k - i - 1]) {
				g = true;
			}
			else {
				g = false;
			}
		}
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		g == true ? std::cout << "Симметричен\n" : std::cout << "Не симметричен\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Желаете продолжить?\n\n Да<Y>    Нет<N>\n\n";
		rewind(stdin);
		std::cin >> answer;
		if (answer == 'Y') {
			system("cls");
			continue;
		}
		while (answer != 'Y') {
			rewind(stdin);
			if (answer == 'N') {
				return 0;
			}
			std::cout << "<Неправильный ввод>\n";
			std::cin >> answer;
			rewind(stdin);
		}
	} while (answer != 'N');
	return 0;
}