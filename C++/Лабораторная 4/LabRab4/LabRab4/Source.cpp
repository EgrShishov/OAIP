#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
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
		std::cout << "������ 1.\n\n������� 10.\n\n���������� ����������� �� ����������� ������ �� k ���������.\n\n�������� ����� ����.\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		std::cout << "������� ���������� ��������� \n";
		int k; int i; bool g;
		/*while (true)
		{
			std::cin >> k;
			if (std::cin.fail()) // ���������� �� �������������
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������,���������� ��� ���\n";
				continue;
			}
			// ������� ����� �������������� ���� �� ������
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "������,���������� ��� ���\n";
				continue;
			}

			if (k <= 0)
			{
				std::cout << "������\n";
				continue;
			}
			break;
		}*/
		while (!checkinput(&k) || k <1) {
			std::cout << "������ �����\n";
			rewind(stdin);
		}
		int a[100];
		std::cout << "������� ������ ����� Enter \n";
		//while (true) {
		//	for (int i = 0; i < k; i++) {
		//		std::cin >> a[i];
		//		if (std::cin.fail()) // ���������� �� �������������
		//		{
		//			std::cin.clear();
		//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//			std::cout << "������,������� ������ � " << i + 1 << "-�� ��������\n";
		//			std::cin >> a[i];
		//			continue;
		//		}
		//	}
		//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//	if (std::cin.gcount() > 1)
		//	{
		//		std::cout << "��������� ���������� ���������\n";
		//		continue;
		//	}
		//	break;
		//}
		for (int i = 0; i < k; i++) {
			while (!arrcheckinput(&a[i])) {
		    std::cout << "������� ������� a[" << i + 1 << "] ������� ������\n";
			rewind(stdin);
			}
		}

		for (i = 0; i < k; i++) {
			if (a[i] == a[k - i - 1]) {
				g = true;
			}
			else {
				g = false;
			}
		}
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		g == true ? std::cout << "�����������\n" : std::cout << "�� �����������\n";
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