#include <iostream>
#include <iomanip>

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
		std::cout << "������ 3.\n\n������� ����� ���������� ��������� �������� ����� � ���������� ��������� ������ �������� �������\n������� 10.\n\n�������� ����� ����.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ������ �������\n";
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

			if (n < 1)
			{
				std::cout << "������\n";
				continue;
			}
			if (n > 7000)
			{
				std::cout << "���,���-�� ����� �� ���. ���������� ����� ��������\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&n) || n < 2) {
			std::cout << "������ �����\n";
			rewind(stdin);
		}

		int** ppta = new int* [n];                       //�������� �������
		for (int i = 0; i < n; i++) {
			ppta[i] = new int[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ppta[i][j] = rand() % 20 + 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << std::setw(3) << ppta[i][j] << " ";
			}
			std::cout << std::endl;
		}

		int sum1 = 0, sum2 = 0;  //��������� �������
		for (int i = 0; i < n; i += 2) {
			int min = ppta[i][0];
			for (int j = 1; j < n; j++) {
				if (ppta[i][j] < min) {
					min = ppta[i][j];
				}
			}
			sum1 += min;
		}

		for (int j = 1; j <n ; j+=2) {
			int max = ppta[0][j];
			for (int i = 1; i < n; i++) {
				if (ppta[i][j] > max) {
					max = ppta[i][j];
				}
			}
			sum2 += max;
		}

		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "min = " << sum1 << " max = " << sum2 << "\n";

		for (int i = 0; i < n; i++) { //������������ ������
			delete[] ppta[i];
		}
		delete[] ppta;

		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ����������?\n\n ��<Y>    ���<N>\n\n";
		rewind(stdin);
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
			rewind(stdin);
		}

	} while (answer != 'N');
	return 0;
}
