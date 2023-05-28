#include <iostream>

int main() {
	int n,sum=0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum = sum + i;
		}
	}
	std::cout << sum;
	return 0;
}