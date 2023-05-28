#include <iostream>

int main() {
	int n, sum,N;
	std::cin >> n;
	if (n % 2 == 0) {
		N = (n) / 2 ;
		sum = (2 + n) / 2 * N;
	}
	else {
		N = (n - 1) / 2 ;
		sum = (1 + n) / 2 * N;
	}
	std::cout << sum;
	return 0;
}