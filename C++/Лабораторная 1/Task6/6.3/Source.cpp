#include <iostream>
#include <cmath>
int main() {
	double x, p, n, K, D, Q ;
	std::cout << "x=";
	std::cin >> x;
	std::cout << "p=";
	std::cin >> p;
	std::cout << "n=";
	std::cin >> n;
	std::cout << "K=";
	std::cin >> K;
	std::cout << "D=";
	std::cin >> D;
	double B = cos(x);
	double C = p - n;
	if (K!=0 && D!=0 ) {
		Q = B*B / (K * D) + B * C * C * C;
		std::cout << "Q=" << Q;
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}