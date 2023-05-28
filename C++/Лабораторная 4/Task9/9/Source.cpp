#include <iostream>

int main() { 
	setlocale(LC_ALL, "ru");
	std::cout << "Задача 9.\n";
	std::cout << "************************************************************************************************************************\n";
	std::cout << "Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел.\nНеобходимо определить диагональ с наибольшей суммой чисел.\n";
	std::cout << "************************************************************************************************************************\n";
	std::cout << "Введите размер массива\n";
	int n;
	std::cin >> n;

	int*** ppta = NULL;
	ppta = (int***)malloc(n * sizeof(int**));
	for (int i = 0; i < n; i++) {
		ppta[i] = (int**)malloc(n * sizeof(int*));
		for (int j = 0; j < n; j++) {
			ppta[i][j] = (int*)malloc(n * sizeof(int));
		}
	}

	for (int i = 0; i < n; i++) { //ввод массива
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ppta[i][j][k]=rand()%20+1;
			}
		}
	}

	for (int i = 0; i < n; i++) { //ввод массива
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				std::cout << ppta[i][k][j]<<" ";
			}
		} std::cout << std::endl;
	}

	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	//обработка массива
	for (int i = 0; i < n; i++) {
		sum1 += ppta[i][i][i];
		sum2 += ppta[i][n - i - 1][i];
		sum3 += ppta[n - i - 1][n - 1 - i][i];
		sum4 += ppta[i][n - 1 - i][i];
	}


	int max1 = std::max(sum1, sum2);
	int max2 = std::max(sum3, sum4);
	int max3 = std::max(max1, max2);
	std::cout << max3 << " <-max\n";

		if (max1 > max2) {
			if (sum1 > sum2) {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][i][i]<<" ";
				}
			}
			else {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][n-1-i][i]<<" ";
				}
			}
		}
		else {
			if (sum3 > sum4) {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[n-i-1][n-i-1][i]<<" ";
				}
			}
			else {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][n-i-1][i]<<" ";
				}
			}
		}

	for (int i = 0; i < n; i++) { //освобождение памяти 
		for (int j = 0; j < n; j++) {
			free(ppta[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		free(ppta[i]);
	}
	free(ppta);

	return 0;
}