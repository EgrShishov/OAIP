#include <iostream>
#include <cmath>
int main() {
	double x, y, C, K, S;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "y=";
	std::cin >> y;
	std::cout << "C=";
	std::cin >> C;
	std::cout << "K=";
	std::cin >> K;
	double A = x + y;
	double D = abs (C-A);
	if (C!=0 && K!=0) {
		S = 10.1 + A / C + D / (K*K);
		std::cout << "S=" << S;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}