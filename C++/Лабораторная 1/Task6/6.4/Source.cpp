#include <iostream>
#include <cmath>
int main() {
	double x, y, z, C, D, T, K;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "y=";
	std::cin >> y;
	std::cout << "z=";
	std::cin >> z;
	std::cout << "C=";
	std::cin >> C;
	std::cout << "D=";
	std::cin >> D;
	std::cout << "K=";
	std::cin >> K;
	double A = x - y;
	double B = sqrt(z);
	if (z>=0 && x<=1 && x>=-1 && (K - C * D)!=0) {
	T = cos(x) + (A*A / (K - C * D)) - B;
	std::cout << "T=" << T;
}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}