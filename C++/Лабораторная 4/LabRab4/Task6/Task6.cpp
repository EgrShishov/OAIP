#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main() {
	// 6 задача
	string s;
	int a[10]{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };  int amount = 10; long long number;
	getline(cin, s);
	cin >> number;

	for (int i = 0; i < s.size(); i++) {
		a[s[i] - '0'] = i;
	}
	for (long long i = 0; i < 10; i++) {
		if (a[i] == (-1)) {
			amount--;
		}
	}

	cout << amount << "\n";
	for (long long i = 0; i < s.size(); i++) {
		if (s[s.size() - i - 1] == s[number - 1]) {
			cout << i << " ";
		}
	}

	/*long long n;
	long long i, count = 0, t=0;
	std::cin >> n;
	long long temp1 = n;
	std::cin >> i;
	while (temp1>0) {
	   temp1 /= 10;
	   t++;
	}

	char p[10000];
	for (long long j = 0; j < t; j++) {
		p[j] = n % 10;
		n = n / 10;
	}

	char s[10000];
	for (long long k = 0; k < t; k++) {
		s[k] = p[k];
	}
	for (long long k = 0; k < t; k++) {
		std::sort(std::begin(s) , std::begin(s) + t);
	}

	for (long long k = 0; k <= t; k++) {
		if (s[k] != s[k + 1]) {
			count++;
		}
	}
	std::cout << count << "\n";

	for (long long j = t - 1; j >= 0; j--) {
		if (p[j] == (i-1)) {
			std::cout << t - i - j<< " ";
		}
	}
	for (long long j = 0; j < t;j++) {
		if (p[j] == i) {
			std::cout << j << " ";
		}
	}*/
	return 0;
}