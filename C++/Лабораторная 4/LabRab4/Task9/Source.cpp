#include <iomanip>
#include <iostream>

bool checkinput(int* k) {
	int scan = scanf_s("%d", k);
	if (scan != 1) {
		return false;
	}
	int count = 0;
	char temp = 0;
	while ((temp = getchar()) != '\n') {
		if ((temp > '9') || (temp < '0') && (temp != ' ') && (temp != '.')) {
			return false;
		}
		if (temp == '.') {
			continue;
		}
		else {
			if (temp == '0') {
				continue;
			}
			else {
				return false;
			}
			continue;
		}
	}
	return true;
}

bool arrcheckinput(int* k) {
	int scan = scanf_s("%d", k);
	char temp = 0;

	while ((temp = getchar()) != '\n') {
		if ((temp > '9') || (temp < '0') && (temp != ' ') && (temp != '.')) {
			return false;
		}
		if (temp == '.') {
			continue;
		}
		else {
			if (temp == '0') {
				continue;
			}
			else {
				return false;
			}
			continue;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "ru");
	system("color 0A");
	char answer;
	do {
		system("cls");
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������ 9.\n\n��� ��������� ������������ ������ �������� n^3 ����� ��������������� �����.\n���������� ���������� ��������� � ���������� ������ �����.\n��� ������ ���������� ������ ������������ ��������� �����.\n\n�������� ����� ����.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ����������� ������� (n) \n";
		int n;
		/*while (true)
		{
			std::cin >> n;
			if (std::cin.fail()) // ���������� �� �������������
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������\n";
				continue;
			}
			// ������� ����� �������������� ���� �� ������
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "������\n";
				continue;
			}
			if (n > 2000) {
				std::cout << "������� �����\n";
				continue;
			}
			if (n <= 0)
			{
				std::cout << "������\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&n) || n < 1) {
			std::cout << "������ �����\n";
			rewind(stdin);
		}

		//��������� ������
		int*** ppta = NULL;
		ppta = (int***)malloc(n * sizeof(int**));
		for (int i = 0; i < n; i++) {
			ppta[i] = (int**)malloc(n * sizeof(int*));
			for (int j = 0; j < n; j++) {
				ppta[i][j] = (int*)malloc(n * sizeof(int));
			}
		}

		std::cout << "������� �������� �������\n";
		//���� ������� rand
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						while (!arrcheckinput(&ppta[i][j][k])) {
							std::cout << "������� ������� a[" << i + 1 << "]" <<"["<< j + 1 << "]"<< k + 1 << "]"<< "������� ������\n";
							rewind(stdin);
						}
						//std::cin >> ppta[i][j][k];
						//if (std::cin.fail()) // ���������� �� �������������
						//{
						//	std::cin.clear();
						//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						//	std::cout << "������\n";
						//	i = 0; j = 0; k = 0;
						//	// ����������� �����
						//	continue;
						//}
					}
				}
			}
			/*std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "��������� ���������� ���������\n";
				continue;
			}
			break;*/


		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		//��������� �������
		for (int i = 0; i < n; i++) {
			sum1 += ppta[i][i][i];
			sum2 += ppta[i][n - i - 1][i];
			sum3 += ppta[n - i - 1][n - 1 - i][i];
			sum4 += ppta[i][n - 1 - i][i];
		}


		//����� ���������
		int max1 = std::max(sum1, sum2);
		int max2 = std::max(sum3, sum4);
		int max3 = std::max(max1, max2);
		std::cout << "��������� � ���������� ������ ����� -> " << max3 << "\n";
		std::cout << "�������� ���������:\n";

		//����� ������������ ��������� � �� ����� �����
		if (max1 > max2) {
			if (sum1 > sum2) {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][i][i] << " ";
				} std::cout << "\n";
			}
			else {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][n - 1 - i][i] << " ";
				} std::cout << "\n";
			}
		}
		else {
			if (sum3 > sum4) {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[n - i - 1][n - i - 1][i] << " ";
				} std::cout << "\n";
			}
			else {
				for (int i = 0; i < n; i++) {
					std::cout << ppta[i][n - i - 1][i] << " ";
				} std::cout << "\n";
			}
		}


		//������������ ������ 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				free(ppta[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			free(ppta[i]);
		}
		free(ppta);


		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ����������?\n\n ��<Y>     ���<N>\n\n";
		std::cin >> answer;
		if (answer == 'Y') {
			system("cls");
			continue;
		}
		while (answer != 'Y') {
			rewind(stdin);
			if (answer == 'N') {
				return 0;
			}
			std::cout << "<������������ ����>\n";
			std::cin >> answer;
		}
		rewind(stdin);
	} while (answer != 'N');
	return 0;
}