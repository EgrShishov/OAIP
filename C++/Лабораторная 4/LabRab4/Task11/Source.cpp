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
		std::cout << "������ 11.\n\n�� ���� ������� ���� ��� ���� � ���� �������� n*m ��������,��� ������ '.' �������� ������ �����, � ������ '*' - �����.\n��������� ��������� ��� ���� �������, ��� � ������������ ����.\n\n�������� ����� ����.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ���������� ����� \n";
		int n, m, count = 0;
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

			if (n <2)
			{
				std::cout << "� ��� ��� ����������? ������� ������\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&n) || n < 1) {
			std::cout << "������ �����\n";
			rewind(stdin);
		}
		std::cout << "������� ���������� �������� \n";
		/*while (true)
		{
			std::cin >> m;
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

			if (m <= 0)
			{
				std::cout << "������\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&m) || m < 1) {
			std::cout << "������ �����\n";
			rewind(stdin);
		}
		std::cout << "������� ����� ����,��������� �� '*' � '.' \n";
		//�������� �������
		char** pta = NULL;
		pta = (char**)malloc(((static_cast<unsigned long long>(n)) + 2) * sizeof(char*));
		for (int i = 0; i < n + 2; i++) {
			pta[i] = (char*)malloc(((static_cast<unsigned long long>(m)) + 2) * sizeof(char));
		}

		//������
		for (int i = 0; i < n + 2; i++)
		{
			for (int j = 0; j < m + 2; j++)
			{
				if ((n == (m + 1) or (n == 0) or (m == 0) or (m == (n + 1)))) {
					pta[i][j] = '.';
				}
			}
		}

		//���� �������
		while (true) {
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < m + 1; j++) {
					std::cin >> pta[i][j];
					while (pta[i][j] != 42 && pta[i][j] != 46)
					{
						std::cout << "�������� ����!������� ���� '*',���� '.': \n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						i = 0; j = 0;
						std::cin >> pta[i][j];
					}
				}
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "������,��������� ���������� ���������\n";
				continue;
			}
			break;
		}

		//����� ��������� �������
		std::cout << "�� ����� ���� ��� ���� \n";
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				std::cout << std::setw(3) << pta[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		//��������� �������
		std::cout << "���������� ����� ����\n";
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (pta[i][j] == '.') {
					if (pta[i - 1][j - 1] == '*') {
						count++;
					}
					if (pta[i - 1][j + 1] == '*') {
						count++;
					}
					if (pta[i + 1][j + 1] == '*') {
						count++;
					}
					if (pta[i + 1][j - 1] == '*') {
						count++;
					}
					if (pta[i][j - 1] == '*') {
						count++;
					}
					if (pta[i][j + 1] == '*') {
						count++;
					}
					if (pta[i + 1][j] == '*') {
						count++;
					}
					if (pta[i - 1][j] == '*') {
						count++;
					}
					std::cout << std::setw(3) << count;
					count = 0;
				}
				else {
					std::cout << std::setw(3) << '*';
				}
			}
			std::cout << std::endl;
		}

		//�������� �������
		for (int i = 0; i < n + 2; i++) {
			free(pta[i]);
		}
		free(pta);

		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ����������?\n��<Y> ���<N>\n";
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