#include <iostream>
#include <sstream>
#include <cmath>

int main() {
	int n; int i = 0;
	int* a = new int[100];
	std::string s;
	int val = 0;
	int size = 0;
	std::getline(std::cin, s);
	std::istringstream iss(s);
	while (iss >> val) {
		if (val != ' ') {
			a[size] = val;
			++size;
		}
	}
	n = size;

	int min = 1, max = 1;  // поиск максимума
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
		}
	}
	else {
		for (int i = max + 1; i < min; i++) {
			a[i] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			count++;
		}
	}

	if (count > n / 2) {  //удаление лишних нулей
		int size = (n - count);
		int* b = new int[size]; // создание массива

		for (int i = 0, j = 0; i < n, j < size; i++) {
			if (a[i] != 0) {
				b[j] = a[i];
				j++;
			}
		}

		for (int i = 0; i < size; i++) {
			std::cout << b[i] << " ";
		}
		delete[] b;
	}
	else {
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " ";
		}
	}
	delete[] a;
	return 0;
}