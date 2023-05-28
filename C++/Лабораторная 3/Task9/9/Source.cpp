#include <iostream>

int main() {
	setlocale(LC_ALL, "ru");
	long long a0,n,an,d;
	std::cout << "a0= ";
	std::cin >> a0;
	std::cout << "d= ";
	std::cin >> d;
	std::cout << "an= ";
	std::cin >> an;
	if (d == 0) {
		std::cout << "проверьте ввод";
	}
	n = (an - a0) / d;
	int t = 1;
	int sum = 0;
	if ((an-a0)%d==0) {
		if (n >=1) {
			for (int i = 0; i <= n; i++) {
				sum += t* (a0 + i * d);
				t *= -2;
			}
			std::cout << "sum= " << sum;
		}
		else {
			std::cout << "проверьте ввод";
		}
	}
	else {
		std::cout << "Такой последовательности не существует";
	}
	return 0;
}