#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

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

bool FLAG = 0;

long long check() {
	long long n;
	bool checkerror = 0;
	bool flag = 1;
	while (true)
	{
		flag = 1;
		std::cin >> n;
		if (n >= 1) {
			if (!std::cin.fail())
			{
				char temp = 0;
				while ((temp = getchar()) != '\n')
				{
					if ((temp > '9') || (temp < '0') && (temp != ' ') && (temp != '.'))
					{
						std::cout << "\nНеверный ввод! Попробуйте снова:\n";
						checkerror = 1;
						break;
					}
					if (temp == '.' && flag)
					{
						flag = 0;
						continue;
					}
					else
					{
						if (temp == '0')
						{
							continue;
						}
						else
						{
							if (FLAG)
							{
								std::cout << "\nНеверный ввод! Кол - во элементов не совпадает с веденным! Введите последний элемент массива:\n";
								checkerror = 1;
								FLAG = 0;
								break;
							}
							else
							{
								std::cout << "\nНеверный ввод! Попробуйте снова:\n";
								checkerror = 1;
								break;
							}
						}
						continue;
					}
				}

				if (checkerror)
				{
					checkerror = 0;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
			}
			else
			{
				std::cout << "\nНеверный ввод! Попробуйте снова:\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			return n;
		}
		else {
			std::cout << "\nНеверный ввод! Попробуйте снова:\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		}
	
}
long long check2() {
	long long n;
	bool checkerror = 0;
	bool flag = 1;
	while (true)
	{
		flag = 1;
		std::cin >> n;
		if (n > 2) {
			if (!std::cin.fail())
			{
				char temp = 0;
				while ((temp = getchar()) != '\n')
				{
					if ((temp > '9') || (temp < '0') && (temp != ' ') && (temp != '.'))
					{
						std::cout << "\nНеверный ввод! Попробуйте снова:\n";
						checkerror = 1;
						break;
					}
					if (temp == '.' && flag)
					{
						flag = 0;
						continue;
					}
					else
					{
						if (temp == '0')
						{
							continue;
						}
						else
						{
							if (FLAG)
							{
								std::cout << "\nНеверный ввод! Кол - во элементов не совпадает с веденным! Введите последний элемент массива:\n";
								checkerror = 1;
								FLAG = 0;
								break;
							}
							else
							{
								std::cout << "\nНеверный ввод! Попробуйте снова:\n";
								checkerror = 1;
								break;
							}
						}
						continue;
					}
				}

				if (checkerror)
				{
					checkerror = 0;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
			}
			else
			{
				std::cout << "\nНеверный ввод! Попробуйте снова:\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			return n;
		}
		else {
			std::cout << "\nНеверный ввод! Попробуйте снова:\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}

}
/*long long checkbutarray() {
	long long n;
	bool checkerror = 0;
	while (true)
	{
		bool flag = 1;
		std::cin >> n;
		if (!std::cin.fail())
		{
			char temp = 0;
			while ((temp = getchar()) != '\n' && temp != ' ')
			{
				if (((temp > '9') || (temp < '0')) && (temp != '.'))
				{
					std::cout << "\nНеверный ввод! Попробуйте снова:\n";
					checkerror = 1;
					break;
				}
				if (temp == '.' && flag)
				{
					flag = 0;
					continue;
				}
				else
				{
					if (temp == '0')
					{
						continue;
					}
					else
					{
						std::cout << "\nНеверный ввод! Попробуйте снова:\n";
						checkerror = 1;
						break;
					}
					continue;
				}
			}
			if (checkerror)
			{
				checkerror = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else
		{
			std::cout << "\nНеверный ввод! Попробуйте снова:\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		return n;
	}
}*/

int main() {
	setlocale(LC_ALL,"ru");
	system("color 0A");
	label:
	std::cout << "============================================Лаборатнорная работа 4=====================================================\n\n";
	std::cout << "Введите номер задачи,которую хотите решить\n\n<1> Симметричность массива\n\n<2> Минимальный элемент\n\n<3> Сумма наименьших элементов нечетных строк и четных столбцов матрицы\n\n<4> Трехмерный динамический массив\n\n<5> Сапер\n\n<6> Магический квадрат\n\n";
	std::cout << "=======================================================================================================================\n\n";
	int N;
	/*while (true)
	{
		std::cin >> N;
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

		if (N <= 0) 
		{
			std::cout << "ошибка\n";
			continue;
		}
		break;
	}*/
	N=check();
	FLAG = 0;

	switch (N) {

	case 1: {
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
			k = check();
			FLAG = 0;
			int a[100];
			std::cout << "Введите массив через пробел \n";
			while (true) {
				for (int i = 0; i < k; i++) {
					std::cin >> a[i];
					if (std::cin.fail()) // извлечение не производилось
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "ошибка,введите заново с "<<i+1<<"-го элемента\n";
						std::cin >> a[i];
						continue;
					}
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (std::cin.gcount() > 1)
				{
					std::cout << "превышено количество элементов\n";
					continue;
				}
				break;
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
				goto label;
				break;
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

	case 2: {
		char answer;
		do {
			system("cls");
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Задача 2.\n\nВариант 10.\n\nНайти минимальный среди элементов, лежащих ниже главной диагонали.\n\nВыполнил Шишов Егор.\n";
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

			int min; bool first = true; //вторая задача
			int i, j;
			const int n = 6, m = 5;      //менять значения тут <-
			int a[n][m] = { {26,27,28,29,30},{-31,32,33,34,35},{12,12,13,14,15},{16,17,18,19,20},{21,0,23,24,25},{36,37,100,39,40} };
			std::cout << "n = " << n << "\n";
			std::cout << "m = " << m << "\n";

			//вывод массива
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					std::cout << std::left << std::setw(3) << a[i][j] << " ";
				}
				std::cout << std::endl;
			}

			//обработка массива и поиск минимума
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (j - i < 0) {
						if (first) {
							min = a[i][j];
							first = false;
						}
						else if (a[i][j] < min) {
							min = a[i][j];
						}
					}
				}
			}

			//какой-то важный код
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Минимальный элемент = " << min << "\n";
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Желаете продолжить?\n\nВведите с клавиатуры Y, если да, и N, если нет\n\n";
			std::cin >> answer;
			if (answer == 'Y') {
				system("cls");
				goto label;
			}
			while (answer != 'Y') {
				rewind(stdin);
				if (answer == 'N') {
					return 0;
				}
				std::cout << "<Неправильный ввод(Y или N)>\n";
				std::cin >> answer;
				rewind(stdin);
			}
		} while (answer != 'N');
		return 0;
	}

	case 3: {
		char answer;
		do {
			system("cls");
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Задача 3.\n\nНайдите сумму наименьших элементов нечетных строк и четных столбцов матрицы\nВариант 10.\n\nВыполнил Шишов Егор.\n";
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Введите размер матрицы\n";
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

				if (n < 1)
				{
					std::cout << "ошибка\n";
					continue;
				}
				if (n > 7000)
				{
					std::cout << "упс,что-то пошло не так. попробуйте числа поменьше\n";
					continue;
				}
				break;
			}*/
			n = check();
			FLAG = 0;

			int** ppta = new int* [n];                       //создание массива
			for (int i = 0; i < n; i++) {
				ppta[i] = new int[n];
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ppta[i][j] = rand() % 20 + 1;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					std::cout << std::setw(3) << ppta[i][j] << " ";
				}
				std::cout << std::endl;
			}

			int sum1 = 0, sum2 = 0;  //обработка массива
			for (int i = 0; i < n; i += 2) {
				int min = ppta[i][0];
				for (int j = 1; j < n; j++) {
					if (ppta[i][j] < min) {
						min = ppta[i][j];
					}
				}
				sum1 += min;
			}

			for (int i = 1; i < n; i += 2) {
				int max = ppta[i][0];
				for (int j = 1; j < n; j++) {
					if (ppta[i][j] > max) {
						max = ppta[i][j];
					}
				}
				sum2 += max;
			}

			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "min = " << sum1 << " max = " << sum2 << "\n";

			for (int i = 0; i < n; i++) { //освобождение памяти
				free(ppta[i]);
			}
			free(ppta);

			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Желаете продолжить?\n\n Да<Y>    Нет<N>\n\n";
			rewind(stdin);
			std::cin >> answer;
			if (answer == 'Y') {
				system("cls");
				goto label;
				break;
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

	case 4: {
		char answer;
		do {
			system("cls");
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Задача 9.\n\nДан трёхмерный динамический массив размером n^3 целых неотрицательных чисел.\nНеобходимо определить диагональ с наибольшей суммой чисел.\nДля обхода диагоналей нельзя использовать вложенные циклы.\n\nВыполнил Шишов Егор.\n";
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Введите размерность массива (n) \n";
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
				if (n > 2000) {
					std::cout << "слишком много\n";
					continue;
				}
				if (n <= 0)
				{
					std::cout << "ошибка\n";
					continue;
				}
				break;
			}*/
			n = check();

			//выделение памяти
			int*** ppta = NULL;
			ppta = (int***)malloc(n * sizeof(int**));
			for (int i = 0; i < n; i++) {
				ppta[i] = (int**)malloc(n * sizeof(int*));
				for (int j = 0; j < n; j++) {
					ppta[i][j] = (int*)malloc(n * sizeof(int));
				}
			}

			std::cout << "Введите элементы массива\n";
			//ввод массива rand
			while (true) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (int k = 0; k < n; k++) {
							std::cin >> ppta[i][j][k];
							if (std::cin.fail()) // извлечение не производилось
							{
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cout << "ошибка\n";
								i = 0; j = 0; k = 0;
								// попробовать снова
								continue;
							}
						}
					}
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (std::cin.gcount() > 1)
				{
					std::cout << "превышено количество элементов\n";
					continue;
				}
				break;
			}


			int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
			//обработка массива
			for (int i = 0; i < n; i++) {
				sum1 += ppta[i][i][i];
				sum2 += ppta[i][n - i - 1][i];
				sum3 += ppta[n - i - 1][n - 1 - i][i];
				sum4 += ppta[i][n - 1 - i][i];
			}


			//поиск максимума
			int max1 = std::max(sum1, sum2);
			int max2 = std::max(sum3, sum4);
			int max3 = std::max(max1, max2);
			std::cout << "Диагональ с наибольшей суммой чисел -> " << max3 << "\n";
			std::cout << "Элементы диагонали:\n";

			//поиск максимальной диагонали и ее вывод вроде
			if (max1 > max2) {
				if (sum1 > sum2) {
					for (int i = 0; i < n; i++) {
						std::cout << ppta[i][i][i] << " ";
					} std::cout << "\n";
				}
				else {
					for (int i = 0; i < n; i++) {
						std::cout << ppta[i][n - 1 - i][i] << " ";
					} std::cout << "\n";
				}
			}
			else {
				if (sum3 > sum4) {
					for (int i = 0; i < n; i++) {
						std::cout << ppta[n - i - 1][n - i - 1][i] << " ";
					} std::cout << "\n";
				}
				else {
					for (int i = 0; i < n; i++) {
						std::cout << ppta[i][n - i - 1][i] << " ";
					} std::cout << "\n";
				}
			}


			//освобождение памяти 
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					free(ppta[i][j]);
				}
			}
			for (int i = 0; i < n; i++) {
				free(ppta[i]);
			}
			free(ppta);


			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Желаете продолжить?\n\n Да<Y>     Нет<N>\n\n";
			std::cin >> answer;
			if (answer == 'Y') {
				system("cls");
				goto label;
			}
			while (answer != 'Y') {
				rewind(stdin);
				if (answer == 'N') {
					return 0;
				}
				std::cout << "<Неправильный ввод>\n";
				std::cin >> answer;
			}
			rewind(stdin);
		} while (answer != 'N');
		return 0;
	}

	case 5: {
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
			n = check();
			FLAG = 0;
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
			m = check();
			FLAG = 0;
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
				goto label;
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

	case 6: {
		char answer;
		do {
			system("cls");
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Задача 13.\n\nПостроить магический квадрат.\n\n";
			std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "Введите порядок квадрата \n";
			system("color 0A");
			long long n;
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
			n = check2();
			FLAG = 0;
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
			} //нечетность
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
				goto label;
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

	default: {
		system("cls");
		std::cout << "Пожалуйста,введите натуральное число от 1 до 6\n";
		goto label;
	}
	}
	return 0;
}

/*int main() { //первая задача
	setlocale(LC_ALL, "ru");
	system("color 0A");
	char answer;
	do {
		system("cls");
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Задача 1.\n\nВариант 10.\n\nОпределить симметричен ли статический массив из k элементов.\n\nВыполнил Шишов Егор.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Введите количество элементов \n";
		unsigned k, i; bool g;
		std::cin >> k;
		int a[100];
		std::cout << "Введите массив через пробел \n";
		for (int i = 0; i < k; i++) {
			std::cin >> a[i];
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
		std::cout << "Желаете продолжить?\n\nДа<Y> Нет<N>\n";
		std::cin >> answer;
		while (answer != 'Y'){
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
}*/

/*int main() {
	setlocale(LC_ALL, "ru");
	system("color 0A");
	char answer;
	do {
		system("cls");
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Задача 2.\n\nВариант 10.\n\nНайти минимальный среди элементов, лежащих ниже главной диагонали.\n\nВыполнил Шишов Егор.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

		int min; bool first = true; //вторая задача
		int i, j;
		const int n = 6, m = 5;      //менять значения тут <-
		int a[n][m] = { {26,27,28,29,30},{-31,32,33,34,35},{12,12,13,14,15},{16,17,18,19,20},{21,0,23,24,25},{36,37,100,39,40} };
		std::cout << "n = " << n << "\n";
		std::cout << "m = " << m << "\n";

		//вывод массива
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				std::cout << std::left << std::setw(3) << a[i][j] << " ";
			}
			std::cout << std::endl;
		}

		//обработка массива и поиск минимума
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (j - i < 0) {
					if (first) {
						min = a[i][j];
						first = false;
					}
					else if (a[i][j] < min) {
						min = a[i][j];
					}
				}
			}
		}

		//какой-то важный код
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Минимальный элемент = " << min << "\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Желаете продолжить?\n\nВведите с клавиатуры Y, если да, и N, если нет\n";
		std::cin >> answer;
		while (answer != 'Y') {
			rewind(stdin);
			if (answer == 'N') {
				return 0;
			}
			std::cout << "<Неправильный ввод(Y или N)>\n";
			std::cin >> answer;
			rewind(stdin);
		}
	} while (answer!='N');
	return 0;
}*/

/*int main() {   // 6 задача
	long long n, i, count = 0, t=0;
	std::cin >> n;
	long long temp1 = n;
	std::cin >> i;
	while (temp1!=0) {
	   temp1 /= 10;
	   t++;
	}
	int p[100]{};
	for (int j = 0; j < t; j++) {
		p[j] = n % 10;
		n = n / 10;
	}

	int s[100]{};
	for (int k = 0; k < t; k++) {
		s[k] = p[k];
	}
	for (int k = 0; k < t; k++) {
		std::sort(std::begin(s) , std::begin(s) + t);
	}

	for (int k = 0; k < t; k++) {
		if (s[k] != s[k + 1]) {
			count++;
		}
	}
	std::cout << count << "\n";

	for (int j = 0; j < t;j++) {
		if (p[j] == i) {
			std::cout << j << " ";
		}
	}

	return 0;
}*/

/*int main() { // 8 задача
	/*const int n = 2, m = 3;
	int a[n][m] = { {1,2,3} ,{4,5,6} };
	int b[m][n] = { {1,2} ,{3,4}, {5,6} };
	int c[n][n] = {};
	int rows1, colums1, rows2, colums2;
	std::cin >> rows1 >> colums1;
	int** ppa = new int* [rows1];
	for (int i = 0; i < rows1; i++) {
		ppa[i] = new int[colums1];
	}
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < colums1; j++) {
			std::cin >> ppa[i][j];
		}
	}

	std::cin >> rows2 >> colums2;

	int** ppb = new int* [rows2];
	for (int i = 0; i < rows2; i++) {
		ppb[i] = new int[colums2];
	}
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < colums2; j++) {
			std::cin >> ppb[i][j];
		}
	}

	int** ppc = new int* [rows1];
	for (int i = 0; i < rows1; i++) {
		ppc[i] = new int[colums2];
	}

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < colums2; j++) {
			ppc[i][j] = 0;
			for (int k = 0; k < colums1 ; k++) {
				ppc[i][j] += ppa[i][k] * ppb[k][j];
			}
		}
	}

	for (int i = 0; i < rows1 ;i++) {
		for (int j = 0; j < colums2 ;j++) {
			std::cout << ppc[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}*/

/* stepik5 int main() { // 5 задача
	int n,m;
	std::cin >> n >> m;
	int a[10][10];
	int b[10][10];

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			if ((j == (m + 1) or (i == 0) or (j == 0) or (i == (n + 1)))) {
				a[i][j] = -10;
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if ((j != m or (i != 0) or (j != 0) or (i != n))) {
				std::cin >> a[i][j];
			}
		}
	}

	int max = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			max = std::max(a[i][j-1],a[i-1][j]);
			if (a[i][j]>max) {
			 max=a[i][j];
			}
			else {
				a[i][j] = max;
			}
			b[i][j] = max;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << b[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
} */

/*int main() {  // 11 задача
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
		std::cin >> n;
		std::cout << "Введите количество столбцов \n";
		std::cin >> m;
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
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				std::cin >> pta[i][j];
			}
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
	}*/

/*int main() { //необходимо дотестировать задача 9
	setlocale(LC_ALL, "ru");
	system("color 0A");
	char answer;
	do {
		system("cls");
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Задача 9.\n\nДан трёхмерный динамический массив размером n^3 целых неотрицательных чисел.\nНеобходимо определить диагональ с наибольшей суммой чисел.\nДля обхода диагоналей нельзя использовать вложенные циклы.\n\nВыполнил Шишов Егор.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Введите размерность массива (n) \n";
		int n;
		std::cin >> n;

		//выделение памяти
		int*** ppta = NULL;
		ppta = (int***)malloc(n * sizeof(int**));
		for (int i = 0; i < n; i++) {
			ppta[i] = (int**)malloc(n * sizeof(int*));
			for (int j = 0; j < n; j++) {
				ppta[i][j] = (int*)malloc(n * sizeof(int));
			}
		}

		//ввод массива rand
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					ppta[i][j][k]=rand()%20+1;
				}
			}
		}


		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		//обработка массива
		for (int i = 0; i < n; i++) {
			sum1 += ppta[i][i][i];
			sum2 += ppta[i][n - i - 1][i];
			sum3 += ppta[n - i - 1][n - 1 - i][i];
			sum4 += ppta[i][n - 1 - i][i];
		}


		//поиск максимума
		int max1 = std::max(sum1, sum2);
		int max2 = std::max(sum3, sum4);
		int max3 = std::max(max1, max2);
		std::cout <<"Диагональ с наибольшей суммой чисел -> " << max3 << "\n";
		std::cout << "Элементы диагонали:\n";

		//поиск максимальной диагонали и ее вывод вроде
		if (max1 > max2) {
			if (sum1 > sum2) {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][i][i] << " ";
				} std::cout << "\n";
			}
			else {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][n - 1 - i][i] << " ";
				} std::cout << "\n";
			}
		}
		else {
			if (sum3 > sum4) {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[n - i - 1][n - i - 1][i] << " ";
				} std::cout << "\n";
			}
			else {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][n - i - 1][i] << " ";
				} std::cout << "\n";
			}
		}


		//освобождение памяти 
		for (int i = 0; i < n; i++) {  
			for (int j = 0; j < n; j++) {
				free(ppta[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			free(ppta[i]);
		}
		free(ppta);


		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Желаете продолжить?\n\n Да<Y>     Нет<N>\n\n";
		std::cin >> answer;
		while (answer != 'Y') {
			rewind(stdin);
			if (answer == 'N') {
				return 0;
			}
			std::cout << "<Неправильный ввод>\n";
			std::cin >> answer;
		}
		rewind(stdin);
	} while (answer != 'N');
	return 0;
} */

/*xz kak delat int main() {
	int index,count=1;
	std::cin >> index;
	int n;
	std::cin >> n;

	int** ppa = new int* [n]; //ввод массива
	for (int i = 0; i < n; i++) {
		ppa[i] = new int[n];
	}

    //заполнение массива
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			ppa[i][j] = count;
			count++;
		}
	}

	for (int i = 0; i < n; i++) { //вывод массива
		for (int j = 0; j < n; j++) {
			std::cout << ppa[i][j];
		}
	}

	for (int i = 0; i < n; i++) { //освобождение памяти
		delete[] ppa[i];
	}
	 
	return 0;
}*/

/*int main() { // задача 3
	int n;
	std::cin >> n;

	int** ppta = new int* [n];                       //создание массива
	for (int i = 0; i < n; i++) {
		ppta[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ppta[i][j]=rand()%20+1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout <<std::setw(3)<< ppta[i][j]<<" ";
		}
		std::cout << std::endl;
	}

	int sum1 = 0, sum2 = 0;  //обработка массива
	for (int i = 0; i < n; i+=2) {
		int min = ppta[i][0];
		for (int j = 1; j < n; j++) {
			if (ppta[i][j] < min) {
				min = ppta[i][j];
			}
		}
		sum1 += min;
	}

	for (int i = 1; i < n; i +=2) {
		int max = ppta[i][0];
		for (int j = 1; j < n; j++) {
			if (ppta[i][j] > max) {
				max = ppta[i][j];
			}
		}
		sum2 += max;
	}

	std::cout << "min = " << sum1 << " max = " << sum2;

	for (int i = 0; i < n; i++) { //освобождение памяти
		free(ppta[i]);
	}
	free(ppta);
	return 0;
}*/

/*int main() { // задача 7
	int n;
	std::cin >> n;

	int* a = new int[n]; // создание массива
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i < n; i++) { //вывод первоначального
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	int min = 0, max = 0;  // поиск максимума
	for (int i = 0; i < n; i++) {
		if (a[i] > a[max]) {
			max = i;
		}
	}

	for (int i = 0; i < n; i++) { // поиск минимума
		if (a[i] < a[min]) {
			min = i;
		}
	}

	int count = 0;
	if (max - min > 0) {  // обработка массива
		for (int i = min + 1; i < max; i++) {
			a[i] = 0;
			count++;
		}
	}
	else {
		for (int i = max + 1; i < min; i++) {
			a[i] = 0;
			count++;
		}
	}

	if (count > n / 2) {  //удаление лишних нулей
		int size = (n - count);
		int* b = new int[size];
		int index;
		int i = 0;

		for (i = 0; i < n; i++) {
			for (int m = i = 0; i < n; i++){
				if (a[i] != '0')  a[m++] = a[i];
		}

		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}

		delete[] b;
	}
	else {
		for (int i = 0; i < n; i++) { // вывод массива a
			std::cout << a[i] << " ";
		}
	}

	delete[] a; //удаление
	return 0;
}*/

/*int main() { //задача 12
	/*long long int n, count = 0;
	std::cin >> n;

	while (count * count < n) { //подсчет сторон
		count++;
	}

	long long int sidesize = count;
	long long int max = count * count;

	long long int** ppa = new long long int* [sidesize];  // создание массива
	for (long long int i = 0; i < sidesize; i++) {
		ppa[i] = new long long int[sidesize];
	}

	do {                                  // заполнение массива
		for (long long int j = 0; j < count- 1; j++) {
			ppa[count - 1][j] = max;
			max--;
		}
		for (long long int i = count - 1; i >= 0; i--) {
			ppa[i][count - 1] = max;
			max--;
		}
		count--;
	} while (max != 0);

	for (long long int i = 0; i < sidesize; i++) {
		for (long long int j = 0; j < sidesize; j++) {
			if (ppa[i][j] == n) {
				std::cout << i << " " << j;
			}
		}
	}

	for (long long int i = 0; i < sidesize; i++) {
		delete ppa[i];
	}
	delete[] ppa;

	long long int n, count = 0;
	std::cin >> n;
	int temp = n;
	count = floor(sqrtl(temp));

	long long int i = count; //столбец с элементом

	long long int* a = new long long int [i];

	for (i; i <= n; i++) {
		a[i] = i;
	}
	for (i; i <= n; i++) {
		if (a[i] == n) {
			std::cout << i << " ";
		}
	}
    return 0;
}*/

/*int main() {
	setlocale(LC_ALL, "ru");
	int n;
	int sum = 0;
	std::cout << "количество удлинителей: ";
	std::cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		std::cout << "количество розеток в " << i + 1 <<" удлинителе: ";
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		sum += a[i]-1;
	}
	std::cout << sum + 1;

	delete[] a;
	return 0;
} */                                                     