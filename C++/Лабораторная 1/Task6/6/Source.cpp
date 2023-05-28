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
	Y = 0.78 * B + pow(A, 3) / K * C * D;
	std::cout << "Y=" << Y;
	return 0;
}