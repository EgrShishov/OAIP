#include <iostream>

double absolute(double x) {
	if (x >= 0) {
		x = x;
	}
	else if (x < 0) {
		x = -x;
	}
	return x;
}

double sinus(double x, double eps) {
	double s=0, an;
	int n=1;
	an = x;
	while (absolute(an)>eps) {
		s = s + an;
		n++;
		an = an * ( -x*x/(2.0*n-1.0)/(2.0*n-2.0));

	}
	return s;
}

int main() {
	double R, P, Q;
	std::cout << "R= ";
	std::cin >> R;
	std::cout << "P= ";
	std::cin >> P;
	std::cout << "Q= ";
	std::cin >> Q;

	if (R > 0 && P > 0 && Q > 0) {
		if (R <= P * sinus(Q, 0.000000001) / 2) {
			std::cout << "YES";
		}
		else {
			std::cout << "NO";
		}
	}
	else {
		std::cout << "ERROR,CHECK YOUR INPUT";
	}
	return 0;
}