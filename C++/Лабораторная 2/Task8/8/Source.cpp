#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
	setlocale(LC_ALL, "ru");
	long double a, b, c, p, q;
	int N;
	std::cout << "Enter N (1 or 2 or 3) = ";
	std::cin >> N;
	if (N>4 || N<0) {
		std::cout << "Неправильный ввод";
	}

	switch (N) {

	case 1:
	{
	std::cout << "Введите a!=0, a= ";
	std::cin >> a;
	std::cout << "Введите b= ";
	std::cin >> b;
	std::cout << "Введите c= ";
	std::cin >> c;
	long double t1, t2;
	long double D1 = b * b - 4 * a * c;
	if (D1 >= 0) {
		if (a != 0) {
			t1 = (-b + sqrtl(D1)) / (2 * a);
			t2 = (-b - sqrtl(D1)) / (2 * a);
		}
		else {
			std::cout << "Ошибка";
			break;
		}
		std::cout << "Уравнение вида ax^4+bx^2+c=0 имеет корни:" << "\n";
		if (t1 > 0 && t2 == 0) {
			std::cout << sqrtl(t1) << ", " << -sqrtl(t1) << "\n";
			std::cout << 0 << "\n";
		}
		else if (t2 > 0 && t1 == 0) {
			std::cout << sqrtl(t2) << ", " << -sqrtl(t2) << "\n";
			std::cout << 0 << "\n";
		}
		else if (t1 > 0 && t2 > 0) {
			std::cout << sqrtl(t1) << ", " << -sqrtl(t1) << "\n";
			std::cout << sqrtl(t2) << ", " << -sqrtl(t2) << "\n";
		}
		else if (t1 > 0) {
			std::cout << sqrtl(t1) << ", " << -sqrtl(t1) << "\n";
		}
		else if (t2 > 0) {
			std::cout << sqrtl(t2) << ", " << -sqrtl(t2) << "\n";
		}
		else if (t1 == 0 && t2 == 0) {
			std::cout << 0 << ", " << 0;
		}
		else {
			std::cout << "Нет корней в вещественных числах" << "\n";
		}
	}
	}
	break;

	case 2:
	{
	std::cout << "Введите a= ";
	std::cin >> a;
	std::cout << "Введите b= ";
	std::cin >> b;
	std::cout << "Введите c= ";
	std::cin >> c;

	long double D3,D4, t;
	D3 = b * b - 4 * a * (c - (2 * a));
	std::cout << "Уравнение вида ax ^ 4 + bx ^ 3 + cx ^ 2 + bx = a = 0 имеет корни : ";
	if (D3 > 0) {
		t = (-b + sqrtl(D3)) / (2 * a); //первый корень
		if (t > 0){
			D4 = t * t - 4;
			if (D4 == 0) { 
				std::cout << t/2 << "\n"; 
			}
			else {
				if (D4 < 0) {

				}
				else {
					std::cout << (t + sqrtl(D4)) / 2 << ", " << (t - sqrtl(D4)) / 2 << "\n";
				}
			}
		}
		
		//второй корень
		t = ((-b - sqrtl(D3)) / (2 * a));
		if (t == 0) { 
			std::cout << -1 <<" " << 1;
		}
		else {
			D4 = t * t - 4;
			if (D4 == 0) { 
				std::cout << t/2 << "\n"; 
			}
			else {
				if (D4 < 0) { 
					 
				}
				else {
					std::cout << (t + sqrtl(D4)) / 2 <<", " << (t - sqrtl(D4)) / 2 << "\n";
				}
			}
		}
	}

	else if (D3 == 0) {
		t = -b / (2 * a);
		if (t == 0) {
			std::cout << 0;
		}
		else {
			D4 = t * t - 4;
			if (D4 < 0) {

			}
			else {
				if (D4 == 0) {
					std::cout << t / 2 << "\n";
				}
				else {
					std::cout << (t + sqrtl(D4)) / 2 << (t - sqrtl(D4)) / 2 << "\n";
				}
			}
		}
	}

	else {
		std::cout << "нет корней";
	}

	}
	break;

	case 3:
	{
	std::cout << "p= ";
	std::cin >> p;
	std::cout << "q= ";
	std::cin >> q;
	long double pi = acos(-1.0);
	long double d = powl(q / 2, 2) + powl(p / 3, 3);
	long double z = sqrtl(d);
	long double y = -q / 2;
	long double x = cbrtl(y + z) + cbrtl(y - z);
	long double fi;
	if (q < 0) {
		fi = atanl(sqrtl(-d) / y);
	}
	else if (q > 0) {
		fi = atanl(sqrtl(-d) / y) + pi;
	}
	else if (q == 0) {
		fi = atanl(pi / 2);
	}
	long double x1 = 2 * sqrtl(-p / 3) * cos(fi / 3);
	long double x2 = 2 * sqrtl(-p / 3) * cos(fi / 3 + 2 * pi / 3);
	long double x3 = 2 * sqrtl(-p / 3) * cos(fi / 3 + 4 * pi / 3);

	if (d > 0) {
		std::cout << "Уравнение вида x^3+px+q=0 имеет вещественный корень:" << "\n";
		std::cout << std::setprecision(8) << x;
	}
	else if (d < 0) {
		std::cout << "Уравнение вида x^3+px+q=0 имеет вещественные корни:" << "\n";
		std::cout << std::setprecision(8) << x1 << ", " << x2 << ", " << x3;
	}
	else if (d == 0) {
		std::cout << "Уравнение вида x^3+px+q=0 имеет два вещественных корня:" << "\n";
		std::cout << std::setprecision(8) << x1 << ", " << x2;
	}
	break;

	}
	}
	return 0;
}