#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL,"ru");
	int n;
	std::cout << "на сколько частей разделить область поиска корня?"<<"\n";
	std::cin >> n;
	double root=0; double x = -1.0;
	double y, step = 1.0 / (n - 1.0);
	double min = fabs(expl(x) * tanl(x) + sinl(x * x) + 0.1);
	y = min;

	for (x = -1.0; x <= 0; x+=step) {
		y = fabs(expl(x) * tanl(x) + sinl(x * x) + 0.1);
		if (y<min) {
			min = y;
			root = x;
		}
	} 
	std::cout << "x= " << root;
	return 0;
}