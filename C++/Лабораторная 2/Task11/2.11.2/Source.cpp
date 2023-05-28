#include <iostream>

int main() {
	double R, P, Q;
	std::cout << "R= ";
	std::cin >> R;
	std::cout << "P= ";
	std::cin >> P;
	std::cout << "Q= ";
	std::cin >> Q;

	if (R > 0 && P > 0) {
		if (R <= P * sinl(Q) / 2) {
			std::cout << "YES";
		}
		else {
			std::cout << "NO";
		}
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}