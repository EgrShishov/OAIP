#include <iostream>
#include <iomanip>
int main() {
	int i = 1;
	long double a, b, N = 0;

	while (i < 31) {
		if (i % 2 == 0) {
			a = i / 2;
			b = i * i * i;
		}
		else {
			a = i;
			b = i * i;
		}
		N = (a - b) * (a - b) + N;
		i++;
	}
	std::cout << std::setprecision(20) << "N= " << N;
	return 0;
}