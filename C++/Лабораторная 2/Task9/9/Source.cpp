#include <iostream>
#include <cmath>
int main() {
	int N;
	double  x, a, b, y, z, f;
	std::cout << "x= ";
	std::cin >> x;
	std::cout << "a= ";
	std::cin >> a;
	std::cout << "b= ";
	std::cin >> b;
	std::cout << "z= ";
	std::cin >> z;
	std::cout << "N= ";
	std::cin >> N;

	if (z<=0) {
		x = z * z / 2;
	}
	else if (z>0) {
		x = sqrt(z);
	}

	switch (N) {

	case 1:
		f = 2 * x;
		break;

	case 2:
		f = x * x * x;
		break;

	case 3:
		f = x / 3;
	    break;
	}
	if (tan(x/2)!=0 && cos(x)!=0) {
		std::cout << "f= " << f << "\n" <<  "N= " << N<<"\n";
		y = f * b / cos(x) + a * log10(abs(tan(x / 2)));
		std::cout << "y= " << y;
	}
	else {
		std::cout << "ERROR"; 
	}
	return 0;
}