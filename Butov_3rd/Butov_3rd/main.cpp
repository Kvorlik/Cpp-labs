#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "class.cpp"
using namespace std;

Table operator + (const Table& a, const Table& b) {
	cout << "* ������ �������� �������� ��� " << &a << " � " << &b << endl;
	Table temp;
	strcat(temp.name, a.name);
	strcat(temp.name, " � ");
	strcat(temp.name, b.name);
	strcat(temp.group, a.group);
	strcat(temp.group, " � ");
	strcat(temp.group, b.group);
	strcat(temp.place, a.place);
	strcat(temp.place, " � ");
	strcat(temp.place, b.place);
	temp.count = a.count + b.count;
	return temp;
}

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
	cout << "������� ������: ";
	cin >> buffer;
	string1.set_group(buffer);
	cout << "������� ����� ��������: ";
	cin >> buffer;
	string1.set_place(buffer);
	string1.set_count();
	cout << "�������� ������ ������:" << endl;
	cout << "������� ��������: ";
	cin >> buffer;
	string2.set_name(buffer);
	cout << "������� ������: ";
	cin >> buffer;
	string2.set_group(buffer);
	cout << "������� ����� ��������: ";
	cin >> buffer;
	string2.set_place(buffer);
	string2.set_count();
	cout << "�������� ������� ������:" << endl;
	cout << "������� ��������: ";
	cin >> buffer;
	string3.set_name(buffer);
	cout << "������� ������: ";
	cin >> buffer;
	string3.set_group(buffer);
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

//������� 4:
	cout << "����������� �������� �� ������������ ������ � ������ �����... " << endl;
	if (string1 == string2) cout << "������ ����������." << endl;
	else cout << "������ ������" << endl;
	cout << "����������� �������� ������ � ������ �����..." << endl;
	Table string4 = string1 + string2;
	cout << "���������." << endl;
	system("pause");
	system("cls");

	cout << "������� ��������� ������� \"��������� ���� �������\"" << endl
		<< "��������\t������\t����� ��������\t����������� ���������" << endl;
	string1.show();
	string2.show();
	string3.show();
	string4.show();

	delete[] buffer;
	system("pause");
	return 0;
}