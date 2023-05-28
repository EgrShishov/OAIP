#include <iostream>
#include <iomanip>

void createsinglemagic(long long** ppa, long long i, long long j, long long size) {

	long long n = size;
	for (long long num = 1; num <= size * size; num++)
	{
		if (j > size - 1)
			j = 0;
		if (i < 0)
			i = size - 1;

		if (ppa[i][j] != 0)
		{
			j--;
			i += 2;
			if (i > size - 1) {
				i -= size;
			}
			if (j < 0) {
				j = size - 1;
			}
		}

		ppa[i][j] = num;
		ppa[i + n][j + n] = num + n * n;
		ppa[i][j + n] = num + n * n * 2;
		ppa[i + n][j] = num + n * n * 3;

		i--;
		j++;
	}
	std::swap(ppa[0][0], ppa[n][0]);
	std::swap(ppa[n - 1][0], ppa[2 * n - 1][0]);
	for (int i = 1; i < n - 1; i++)
	{
		std::swap(ppa[i][1], ppa[i + n][1]);
	}
}

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
		std::cout << "Задача 13.\n\nПостроить магический квадрат.\n\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Введите порядок квадрата \n";
		system("color 0A");
		int n;
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

			if (n <= 0)
			{
				std::cout << "ошибка\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&n) || n <3) {
			std::cout << "Ошибка ввода\n";
			rewind(stdin);
		}
		long long** ppa;
		ppa = (long long**)calloc(n, sizeof(long long*));
		for (int i = 0; i < n; i++) {
			ppa[i] = (long long*)calloc(n, sizeof(long long));
		}

		//обработка массива
		if (n % 2 != 0) { //нечетный порядок
			int i = 0;
			int j = n / 2;
			for (int num = 1; num <= n * n; num++)
			{
				if (j > n - 1)
					j = 0;
				if (i < 0)
					i = n - 1;

				if (ppa[i][j] != 0)
				{
					j--;
					i += 2;
					if (i > n - 1) {
						i -= n;
					}
					if (j < 0) {
						j = n - 1;
					}
				}
				ppa[i][j] = num;
				i--;
				j++;
			}
		} //четность 4к
		else if (n % 4 == 0) {
			long long i, j;
			long long max = n * n;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					ppa[i][j] = (n * i) + j + 1;
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (((i % 4 == 0 || i % 4 == 3) && (j % 4 == 1 || j % 4 == 2)) || ((i % 4 == 1 || i % 4 == 2) && (j % 4 == 0 || j % 4 == 3))) {

					}
					else {
						ppa[i][j] = max + 1 - ppa[i][j];
					}
				}
			}
			/*for (i = 0; i < n / 4; i++)
			{
				for (j = 0; j < n / 4; j++)
				{
					ppa[i][j] = (n * n + 1) - ppa[i][j];
				}
			}
			for (i = 0; i < n / 4; i++)
			{
				for (j = 3 * (n / 4); j < n; j++)
				{
					ppa[i][j] = (n * n + 1) - ppa[i][j];
				}
			}
			for (i = 3 * n / 4; i < n; i++)
			{
				for (j = 0; j < n / 4; j++)
				{
					ppa[i][j] = (n * n + 1) - ppa[i][j];
				}
			}
			for (i = 3 * n / 4; i < n; i++)
			{
				for (j = 3 * n / 4; j < n; j++)
				{
					ppa[i][j] = (n * n + 1) - ppa[i][j];
				}
			}
			for (i = n / 4; i < 3 * n / 4; i++)
			{
				for (j = n / 4; j < 3 * n / 4; j++)
				{
					ppa[i][j] = (n * n + 1) - ppa[i][j];
				}
			}*/

		}
		else if (n % 4 == 2) {

			int temp = n;

			if (temp % 4 == 2)
			{
				temp = temp / 2;
				createsinglemagic(ppa, 0, temp / 2, temp);
			}

		}

		//вывод квадрата
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << std::setw(3) << ppa[i][j] << " ";
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < n; i++) {
			free(ppa[i]);
		}
		free(ppa);

		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Желаете продолжить?\n\n Да<Y>   Нет<N>\n\n";
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