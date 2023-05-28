#include <iostream>
#include <iomanip>

int main() {
	int min; bool first = true; //вторая задача
	int i, j;
	const int rows = 6, colums = 5;
	int a[rows][colums] = { {26,27,28,29,30},{-31,32,33,34,35},{12,12,13,14,15},{16,17,18,19,20},{21,0,23,24,25},{36,37,100,39,40} };
	std::cout << "n = " << rows << "\n";
	std::cout << "m = " << colums << "\n";
	for (i = 0; i < rows; i++) {
		for (j = 0; j < colums; j++) {
			std::cout << std::left << std::setw(3) << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < colums; j++) {
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
	std::cout << "min = " << min;
	return 0;
}