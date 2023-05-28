#include <iostream>
#include <cmath>
int main() {
	int h1, min1, h2, min2, t1, t2, h3, min3, dx;
	std::cout << "h1 = ";
	std::cin >> h1;
	std::cout << "min1 = ";
	std::cin >> min1;
	std::cout << "h2 = ";
    std::cin >> h2;
	std::cout << "min2 = ";
	std::cin >> min2;

	t1 = h1 * 60 + min1;
	t2 = h2 * 60 + min2;

	if (h1 <= 24 && h1 >= 0 && min1 <= 59 && min1 >= 0 && h2 <= 24 && h2 >= 0 && min2 >= 0 && min2 <= 59) {
		if (h2 >= h1) {
			h3 = (t2 - t1) / 60;
			min3 = ((t2 - t1) - (h3 * 60));
			}
		else {
				dx = 24 * 60 - (t1);
					h3 = (dx + t2) / 60; 
					min3 =( (dx + t2) - h3 * 60);
			}
		std::cout << h3 << " hours " << min3 << " minutes";
	}
	else {
		std::cout << "ERROR";
	}
	return 0;
}