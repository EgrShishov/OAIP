#include <iostream>

int main() {
	double A = 0, M = 20;
	double x=0, y, B = acos(-1.0) / 2, H = (B - A) / M;

	for (int i = 0; x<B ; i++) {	
			x = A + i * H;
			y = sin(x) - cos(x);
			std::cout << y << "\n";
	} 
	return 0; 
}