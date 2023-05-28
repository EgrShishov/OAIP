#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

long double absolute(long double x) {
	if (x >= 0) {
		x = x;
	}
	else if (x < 0) {
		x = -x;
	}
	return x;
}

long double sinus(long double x) {
	long double s = 0, an; double eps = 1e-20;
	int n = 1;
	x = fmodl(x, 2 * M_PI);
	an = x;
	while (absolute(an) > eps) {
		s = s + an;
		n++;
		an = an * (-x * x / (2.0 * n - 2.0) / (2.0 * n - 1.0));
	}
	return s;
}

long double cosinus(long double x) {
	long double s = 1, an = 1; double eps = 1e-20;
	int n = 0;
	x = fmodl(x, 2 * M_PI);
	while (absolute(an) > eps) {
		an = -(an * x * x) / ((2 * n + 2.0) * ( 2 * n + 1.0));
		s = s + an;
		n++;
	}
	return s;
}


long double logarifm(long double x) {
	long double i = 1, s = 0, n = 1e6, y, z, t = 1;
	int count = 0;
	long double exp = 2.7182818284590452;
	if (x == 1) {
		return 0;
	}
	if (x > 3) {
		while (x > 3) {
			x = x / exp;
			count++;
		}
	}
	else if (x < 3) {
		while (x < 3) {
			x = x * exp;
			count--;
		}
	}
	z = (x + 1) / (x - 1);
	long double step = ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));
	while (i <= n) {
		z = z * step;
		y = z / t;
		s = s + y;
		t = t + 2;
		i++;
	}
	return  2 * s + count;
}

int main() {
	system("color F3");
	long double x;
	std::cout << "Enter x = ";
	std::cin >> x;
	std::cout << "-----------------------------------------------------------------------------------------------------------------\n";
	long double c = logarifm(absolute(x));
	long double a = sinus(x);
	long double b = cosinus(x);
	long double min;

	if (a > c) {
		min = c;
	}
	else {
		min = a;
	}

	if (min > b) {
		min = b;
	}
	std::cout << "min= " << std::setprecision(22) << min << "\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------------\n";
	std::cout << "sin= " << a << "    " << sinl(x) << "\n";
	std::cout << "cos= " << b << "    " << cosl(x) << "\n";
	std::cout << "ln= " << c << "    " << logl(absolute(x)) << "\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------------\n";

	return 0;
}