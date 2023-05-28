#include <iostream>
#include <cmath>
int main() {
	double x, p, h, K, C, D, Y;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "p=";
	std::cin >> p;
	std::cout << "h=";
	std::cin >> h;
	std::cout << "C=";
	std::cin >> C;
	std::cout << "D=";
	std::cin >> D;
	std::cout << "K=";
	std::cin >> K;
	double A = x - p;
	double B = log(h); 
	if (K*C*D !=0 && h>0) {
		Y = 0.78 * B + (A*A*A) / K * C * D;
		std::cout << "Y=" << Y;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}