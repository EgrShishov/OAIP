#include <iostream>

int main() {
	double a, b, c;
	int N;
	std::cin >> a >> b >> c >> N;

	switch (N) {
	   
	case 2: 
		std::cout << "Y= " << b * c - a * a;
		break;
	   
	case 56:
	   std::cout << "Y= " << b * c;
	   break;

	 case 7:
		std::cout << "Y= " << a * a * a * a * a * a * a + c;
		break;
       
	 case 3:
	   std::cout << "Y= " << a - b * c;
	   break;

	 default:
	   std::cout << "Y= " << (a + b) * (a + b) * (a + b);
	   break;
		   
	}

	return 0;
}