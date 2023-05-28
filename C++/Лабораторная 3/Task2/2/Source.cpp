#include <iostream>
#include <cmath>
int main() {
	double eps =1e-3;
	long double S=0;
	long double d;
	int n=1;
	do {
		d = powl(1.0/2, n) + powl(1.0/3, n);
		S = S + d;
		n++;
	} while (d >= eps);
	std::cout << S;
	return 0;
}