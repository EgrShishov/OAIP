#include <iostream>
int main() {
	int n, m;
	std::cin >> n >> m;
	int a[100][100];
	int b[100][100];

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			if ((j == (m + 1) or (i == 0) or (j == 0) or (i == (n + 1)))) {
				a[i][j] = -10;
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if ((j != m or (i != 0) or (j != 0) or (i != n))) {
				std::cin >> a[i][j];
			}
		}
	}

	int max = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			max = std::max(a[i][j - 1], a[i - 1][j]);
			if (a[i][j] > max) {
				max = a[i][j];
			}
			else {
				a[i][j] = max;
			}
			b[i][j] = max;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << b[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}