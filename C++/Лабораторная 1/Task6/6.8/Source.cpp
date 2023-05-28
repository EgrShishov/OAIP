#include <iostream>
#include <cmath>
int main() {
	double x, d, C, K, Y ;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "d=";
	std::cin >> d;
	std::cout << "C=";
	std::cin >> C;
	std::cout << "K=";
	std::cin >> K;
	double A = log10(x);
	double B = x+ exp(d);
	if (K!=0 && x<=1 && x>=-123) {
		Y = (A + B) - (C*C/ K);
		std::cout << "Y=" << Y;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}