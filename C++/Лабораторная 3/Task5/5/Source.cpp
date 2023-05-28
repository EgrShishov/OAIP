#include <iostream>
#include <iomanip>
int main() {
	int n, N, k; long double x, X,sum;
	std::cin >> n >> N;
	for (int i = 0; i < N; i++) {
		std::cout << "x must be in interval from 0.1 to 1.0, x= ";
		std::cin >> x;
	    sum = x;
		k = n;
		while (k>0) {
			X = powl(-1.0, k) * powl(x, 2.0 * k + 1.0) / (2.0 * k + 1.0);
			sum = sum + X;
			k--;
		}
		std::cout << std::setprecision(22)<< sum << " " << atanl(x)<< "\n";
	}
	return 0;
}