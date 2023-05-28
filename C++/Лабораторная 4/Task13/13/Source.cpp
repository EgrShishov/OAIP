#include <iostream>
#include <iomanip>


int main() {
	std::cout << "Welcome back,Neo.Input size of the magic square\n";
	system("color 0A");
	int n;
	std::cin >> n;
    int** ppa;
	ppa = (int**)calloc(n,sizeof(int*));
	for (int i = 0; i < n; i++) {
		ppa[i] = (int*)calloc(n,sizeof(int));
	}

	if (n % 2 != 0) {
		//нечетность 
		int i = n / 2;
		int j = n - 1;
		for (int num = 1; num <= n * n; num++)
		{
			if (i == -1 && j == n)
			{
				j = n - 2;
				i = 0;
			}
			else
			{
				if (j == n)
					j = 0;
				if (i < 0)
					i = n - 1;
			}
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
	}
	/*if (n % 4 == 0) {
		/*int x = 0, y = 0;
		for (int i = 1; i < n * n; i++) {
			ppa[x][y] = i;
			y++;
			if (y > n - 1) {
				x++;
				y = y - n;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 4 == 0 && j % 4 == 0) {
					for (int k = 0; k < 4; k++) {
						ppa[i + k][j + k] = (n * n + 1) - ppa[i + k][j + k];
					}
				}
				else if (i % 4 == 3 && j % 4 == 0) {
					for (int k = 0; k < 4; k++) {
						ppa[i - k][j - k] = (n * n + 1) - ppa[i - k][j - k];
					}
				}
			}
		}*/
		/*int** temp = new int* [n];
		temp = (int**)calloc(n, sizeof(int));
		for (int i = 0; i < n; i++) {
			ppa[i] = (int*)calloc(n, sizeof(int));
		}
		int size = 4;
		int x = 0, y = 0;
		for (int i = 0; i < n * n / 16; i++) {
			if (x == sqrtl(double(n*n)/16)) {
				x = 0;
				y++;
			}
			for (int j = 0; j < 4; j++) {
				ppa[size * y + j][size * x + j] == temp[size * y + j][size * x + j];
				ppa[size * y + j][size * x + size - 1 - j] = temp[size * y + j][size * x + size - 1 - j];
			}
			x++;
		}
	}*/
	else if ((4 * n + 2) % 2 == 0) {
		// Заполнение II четверти 
		int num = 0;
		int size_1 = n / 2;
		int i = 0;
		int j = size_1 / 2;
		for (num = 1; num < size_1 * size_1 + 1; num++)
		{
			if (i < 0)
			{
				i = size_1 - 1;
			}
			if (j > size_1 - 1)
			{
				j = 0;
			}
			if (ppa[i][j] != 0)
			{
				i = i + 2;
				j = j - 1;
				if (i > size_1 - 1)
				{
					i = i - size_1;
				}
				if (j < 0)
				{
					j = size_1 - 1;
				}
			}
			ppa[i][j] = num;
			i--;
			j++;
		}
		i = size_1;
		j = size_1 + size_1 / 2;
		for (; num < size_1 * size_1 * 2 + 1; num++)
		{
			if (i < size_1)
			{
				i = size_1 + size_1 - 1;
			}
			if (j > size_1 * 2 - 1)
			{
				j = size_1;
			}
			if (ppa[i][j] != 0)
			{
				i = i + 2;
				j = j - 1;
				if (i > size_1 * 2 - 1)
				{
					i = i - size_1;
				}
				if (j < size_1)
				{
					j = size_1 * 2 - 1;
				}
			}
			ppa[i][j] = num;
			i--;
			j++;
		}
		i = 0;
		j = size_1 + size_1 / 2;
		for (; num < size_1 * size_1 * 3 + 1; num++)
		{
			if (i < 0)
			{
				i = size_1 - 1;
			}
			if (j > size_1 * 2 - 1)
			{
				j = size_1;
			}
			if (ppa[i][j] != 0)
			{
				i = i + 2;
				j = j - 1;
				if (i > size_1 - 1)
				{
					i = i - size_1;
				}
				if (j < size_1)
				{
					j = size_1 * 2 - 1;
				}
			}
			ppa[i][j] = num;
			i--;
			j++;
		}
		// Заполнение III четверти 
		i = size_1;
		j = size_1 / 2;
		for (; num < size_1 * size_1 * 4 + 1; num++)
		{
			if (i < size_1)
			{
				i = size_1 + size_1 - 1;
			}
			if (j > size_1 - 1)
			{
				j = 0;
			}
			if (ppa[i][j] != 0)
			{
				i = i + 2;
				j = j - 1;
				if (i > size_1 * 2 - 1)
				{
					i = i - size_1;
				}
				if (j < 0)
				{
					j = size_1 - 1;
				}
			}
			ppa[i][j] = num;
			i--;
			j++;
		}
		// Переставление нужных элементов 
		int temp = 0;
		int amount_c = size_1 / 2 - 1;
		if (amount_c != 0) {
			for (i = 0; i < size_1; i++)
			{
				for (j = size_1 - amount_c; j < size_1 + 1; j++)
				{
					temp = ppa[i][j];
					ppa[i][j] = ppa[i + size_1][j];
					ppa[i + size_1][j] = temp;
				}
			}
		}
		temp = ppa[0][0];
		ppa[0][0] = ppa[size_1][0];
		ppa[size_1][0] = temp;
		temp = ppa[size_1 - 1][0];
		ppa[size_1 - 1][0] = ppa[n - 1][0];
		ppa[n - 1][0] = temp;
		for (i = 1; i < size_1 - 1; i++)
		{
			temp = ppa[i][1];
			ppa[i][1] = ppa[i + size_1][1];
			ppa[i + size_1][1] = temp;
		}
	}
		/*if (n % 4 == 0) {   //одинарная четность
			int x = 0, y = 0;
			for (int i = 1; i < n * n; i++) {
				ppa[x][y] = i;
				y++;
				if (y > n - 1) {
					x++;
					y = y - n;
				}
			}
			for (int i = 0; i < n;i++) {
				for (int j = 0; j < n; j++) {
					if (i % 4 == 0 && j % 4 == 0) {
						for (int k = 0; k < 4; k++) {
							ppa[i + k][j + k] = (n * n + 1) - ppa[i + k][j + k];
						}
					}
					else if (i % 4 == 3 && j % 4 == 0) {
						for (int k = 0; k < 4; k++) {
							ppa[i - k][j - k] = (n * n + 1) - ppa[i - k][j - k];
						}
					}
				}
				}
		}*///двойая четность

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
	return 0;
}