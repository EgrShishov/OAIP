#include <iostream>

double mn(double x) {

	return 8 + x * (23 * (x + 3) * x + 32);
}
int main() {
	double x;
	std::cin >> x;	
	std::cout << mn(x) << "\n";
	std::cout << mn(-x);
	return 0; 
}
