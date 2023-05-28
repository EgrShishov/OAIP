#include <iostream>
#include <cmath>
int main() {
	double x, Y, K, p, D, C;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "K=";
	std::cin >> K;
	std::cout << "p=";
	std::cin >> p;
	std::cout << "D=";
	std::cin >> D;
	std::cout << "C=";
	std::cin >> C;

		double A = x + sin(p);
		double B = exp(K);
		if (A!=0 && B!=0) {
		Y = 1 + (( K * K )/ (2 * A * B)) - B + D * C;
		std::cout << "Y=" << Y;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}