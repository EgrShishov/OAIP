#include <iostream>

int main() {
	setlocale(LC_ALL,"Russian");
	long double x1, y1, x2, y2, r, R;
	std::cout << "x1= ";
	std::cin >> x1;
	std::cout << "y1= ";
	std::cin >> y1;
	std::cout << "r= ";
	std::cin >> r;
	std::cout << "x2= ";
	std::cin >> x2;
	std::cout << "y2= ";
	std::cin >> y2;
	std::cout << "R= ";
	std::cin >> R;

	long double l = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	if (r>0 && R>0) {
		if (l + R <= r && R!=r) {
			std::cout << "Да, но справедливо обратное для двух фигур";
		}
		else if (l + r <= R && R!=r) {
			std::cout << "Да";
		}
		else if (fabs(R - r) < l < R + r ) {
			if (x1==x2 && y1==y2 && r==R) {
				std::cout << "Ни одно условие не выполнено"; 
			}
			else {
				std::cout << "Фигуры пересекаются";
			}
		}
		else {
			std::cout << "Ни одно условие не выполнено" ;
		}
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}