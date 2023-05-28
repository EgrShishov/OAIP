#include <iostream>
#include <iomanip>

int main() {  // 11 задача
	int n, m, count = 0;
	std::cin >> n >> m;

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
				pta[i][j] = '-';
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
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << std::setw(3) << pta[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//обработка массива
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (pta[i][j] == '-') {
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

	return 0;
}