#include <iostream>
#include <iomanip>
int main() { // 8 задача
	int rows1, colums1, rows2, colums2;
	std::cin >> rows1;
	/*int ppa[rows1][rows1];*/
	int** ppa = new int* [rows1];
	for (int i = 0; i < rows1; i++) {
		ppa[i] = new int[rows1];
	}
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < rows1; j++) {
			std::cin >> ppa[i][j];
		}
	}

	std::cin >> rows2;

	/*int ppb[rows2][rows2];*/
	int** ppb = new int* [rows1];
	for (int i = 0; i < rows2; i++) {
		ppb[i] = new int[rows2];
	}
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < rows2; j++) {
			std::cin >> ppb[i][j];
		}
	}

	/*int ppc[rows1][rows2];*/
	int** ppc = new int* [rows1];
	for (int i = 0; i < rows1; i++) {
		ppc[i] = new int[rows2];
	}
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < rows2; j++) {
			ppc[i][j] = 0;
			for (int k = 0; k < rows1; k++) {
				ppc[i][j] += ppa[i][k] * ppb[k][j];
			}
		}
	}

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < rows2; j++) {
			if (j != rows2 - 1) {
				std::cout << ppc[i][j] << " ";
			}
			else {
				std::cout << ppc[i][j];
			}
		}
		std::cout << "\n";
	}

	for (int i = 0; i < rows1; i++) {
		delete ppa[i];
	}
	delete[] ppa;

	for (int i = 0; i < rows2; i++) {
		delete ppb[i];
	}
	delete[] ppb;

	for (int i = 0; i < rows1; i++) {
		delete ppc[i];
	}
	delete[] ppc;

	return 0;
}