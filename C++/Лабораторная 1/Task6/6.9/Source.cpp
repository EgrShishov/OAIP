#include <iostream>
#include <cmath>
int main() {
	double x, z, p, K, C, D, Y;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "p=";
	std::cin >> p;
	std::cout << "z=";
	std::cin >> z;
	std::cout << "C=";
	std::cin >> C;
	std::cout << "D=";
	std::cin >> D;
	std::cout << "K=";
	std::cin >> K;
	double A = sin(x) - z;
	double B = abs(p - x);
	if (C*D!=0) {
		Y = (A+B)*(A+B) - K / (C * D);
		std::cout << "Y=" << Y;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}