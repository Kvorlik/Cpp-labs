#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "class.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	char* buffer = new char[20];
	Table string1;
	Table string2;
	Table string3;

	cout << "������� ��������� ������� \"��������� ���� �������\"" << endl
		<< "��������\t������\t����� ��������\t����������� ���������" << endl;
	string1.show();
	string2.show();
	string3.show();
	system("pause");
	system("cls");

	cout << "���������� �������." << endl
		<< "�������� ������ ������:" << endl
		<< "������� ��������: ";
	cin >> buffer;
	string1.set_name(buffer);
	string1.set_group();
	cout << "������� ����� ��������: ";
	cin >> buffer;
	string1.set_place(buffer);
	string1.set_count();
	cout << "�������� ������ ������:" << endl;
	cout << "������� ��������: ";
	cin >> buffer;
	string2.set_name(buffer);
	string2.set_group();
	cout << "������� ����� ��������: ";
	cin >> buffer;
	string2.set_place(buffer);
	string2.set_count();
	cout << "�������� ������� ������:" << endl;
	cout << "������� ��������: ";
	cin >> buffer;
	string3.set_name(buffer);
	string3.set_group();
	cout << "������� ����� ��������: ";
	cin >> buffer;
	string3.set_place(buffer);
	string3.set_count();
	system("pause");
	system("cls");

	cout << "������� ��������� ������� \"��������� ���� �������\"" << endl
		<< "��������\t������\t����� ��������\t����������� ���������" << endl;
	string1.show();
	string2.show();
	string3.show();

	delete[] buffer;
	system("pause");
	return 0;
}