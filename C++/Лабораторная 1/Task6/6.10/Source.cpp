#include <iostream>
#include <cmath>
int main() {
	double x, z, k, D, C, Y;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "z=";
	std::cin >> z;
	std::cout << "C=";
	std::cin >> C;
	std::cout << "D=";
	std::cin >> D;
	std::cout << "k=";
	std::cin >> k;
	
	double A = log(x) - k;
	double B = sqrt(z);
	if (z>=0 && x>0 && A!=0) {
		Y = D*D + C*C / (0.75 * A) + B;
		std::cout << "Y=" << Y;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}
