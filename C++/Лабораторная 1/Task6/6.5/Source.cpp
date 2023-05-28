#include <iostream>
#include <cmath>
int main() {
	double n, m, K, x, Y;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "n=";
	std::cin >> n;
	std::cout << "m=";
	std::cin >> m;
	std::cout << "K=";
	std::cin >> K;
	double A = abs(n+m);
	double D = tan(x);
	if (A != 0) {
		Y = 1.29 + K / A + D*D;
		std::cout << "Y=" << Y;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}