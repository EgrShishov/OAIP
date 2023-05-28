#include <iostream>
#include <iomanip>

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
		std::cout << "Задача 11.\n\nНа вход подаётся поле для игры в сапёр размером n*m символов,где символ '.' означает пустое место, а символ '*' - бомбу.\nТребуется дополнить это поле числами, как в оригинальной игре.\n\nВыполнил Шишов Егор.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Введите количество строк \n";
		int n, m, count = 0;
		/*while (true)
		{
			std::cin >> n;
			if (std::cin.fail()) // извлечение не производилось
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "ошибка\n";
				continue;
			}
			// очищаем любой дополнительный ввод из потока
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "ошибка\n";
				continue;
			}

			if (n <2)
			{
				std::cout << "а еще что придумаете? введите заново\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&n) || n < 1) {
			std::cout << "Ошибка ввода\n";
			rewind(stdin);
		}
		std::cout << "Введите количество столбцов \n";
		/*while (true)
		{
			std::cin >> m;
			if (std::cin.fail()) // извлечение не производилось
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "ошибка\n";
				continue;
			}
			// очищаем любой дополнительный ввод из потока
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "ошибка\n";
				continue;
			}

			if (m <= 0)
			{
				std::cout << "ошибка\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&m) || m < 1) {
			std::cout << "Ошибка ввода\n";
			rewind(stdin);
		}
		std::cout << "Введите карту поля,состоящую из '*' и '.' \n";
		//создание массива
		char** pta = NULL;
		pta = (char**)malloc(((static_cast<unsigned long long>(n)) + 2) * sizeof(char*));
		for (int i = 0; i < n + 2; i++) {
			pta[i] = (char*)malloc(((static_cast<unsigned long long>(m)) + 2) * sizeof(char));
		}

		//бордюр
		for (int i = 0; i < n + 2; i++)
		{
			for (int j = 0; j < m + 2; j++)
			{
				if ((n == (m + 1) or (n == 0) or (m == 0) or (m == (n + 1)))) {
					pta[i][j] = '.';
				}
			}
		}

		//ввод массива
		while (true) {
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < m + 1; j++) {
					std::cin >> pta[i][j];
					while (pta[i][j] != 42 && pta[i][j] != 46)
					{
						std::cout << "Неверный ввод!Введите либо '*',либо '.': \n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						i = 0; j = 0;
						std::cin >> pta[i][j];
					}
				}
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "ошибка,превышено количество элементов\n";
				continue;
			}
			break;
		}

		//вывод введеного массива
		std::cout << "Вы ввели поле для игры \n";
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				std::cout << std::setw(3) << pta[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		//обработка массива
		std::cout << "Полученная карта поля\n";
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (pta[i][j] == '.') {
					if (pta[i - 1][j - 1] == '*') {
						count++;
					}
					if (pta[i - 1][j + 1] == '*') {
						count++;
					}
					if (pta[i + 1][j + 1] == '*') {
						count++;
					}
					if (pta[i + 1][j - 1] == '*') {
						count++;
					}
					if (pta[i][j - 1] == '*') {
						count++;
					}
					if (pta[i][j + 1] == '*') {
						count++;
					}
					if (pta[i + 1][j] == '*') {
						count++;
					}
					if (pta[i - 1][j] == '*') {
						count++;
					}
					std::cout << std::setw(3) << count;
					count = 0;
				}
				else {
					std::cout << std::setw(3) << '*';
				}
			}
			std::cout << std::endl;
		}

		//удаление массива
		for (int i = 0; i < n + 2; i++) {
			free(pta[i]);
		}
		free(pta);

		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Желаете продолжить?\nДа<Y> Нет<N>\n";
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