#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << "a=" << a << " b=" << b << "\n";
		a ^= b ;
		std::cout << "a=" << a << " b=" << b << "\n";
		b ^= a;
		std::cout << "a=" << a << " b=" << b << "\n";
		a ^= b;
		std::cout << "a=" << a << " b=" << b << "\n";
	return 0;
}