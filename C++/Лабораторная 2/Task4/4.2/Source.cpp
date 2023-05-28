#include <iostream>

int main() {
	double x, y;
	std::cin >> x >> y;
	bool max (x > y);
	std::cout << "max = " << (max ? x : y);
	return 0;
}