#include <iostream>
#include <locale>
#include <forward_list>
#include "module.cpp"
using namespace std;

void add(Day& diary, forward_list<Day>& list, forward_list<Day>::iterator& iter) {
	int d, m;
	string obj;
	cout << "������� �����: ";			cin >> d;
	cout << "������� �����: ";			cin >> m;
	cout << "�������� ������ ���: ";	cin >> obj;
	diary.add(d, m, obj, list, iter);
}
void read(Day& diary, forward_list<Day>& list) {
	int d, m;
	cout << "������� �����: "; cin >> d;
	cout << "������� �����: "; cin >> m;
	diary.read(d, m, list);
}
void write(Day& diary, forward_list<Day>& list) {
	int d, m;
	string obj;
	cout << "������� �����: ";			cin >> d;
	cout << "������� �����: ";			cin >> m;
	cout << "�������� ������ ���: ";	cin >> obj;
	diary.write(d, m, obj, list);
}

int main() {
	setlocale(LC_ALL, "rus");
	int d, m;
	string buffer;
	forward_list<Day> list;
	forward_list<Day>::iterator iter;

	cout << "�������� ������." << endl;
	cout << "������� �����: ";			cin >> d;
	cout << "������� �����: ";			cin >> m;
	cout << "�������� ������ ���: ";	cin >> buffer;
	Day diary(d, m, buffer);
	list.push_front(diary);
	iter = list.begin();

	int menu = 0;
	do {
		system("pause");
		system("cls");
		cout << "1) �������� ���-�� ������� ������." << endl
			<< "2) �������� ������." << endl
			<< "3) ��������� ������ ��� �� ����." << endl
			<< "4) �������� ������ ��� �� ����." << endl
			<< "5) ����� �� ���������." << endl
			<< "�������� �������� (1-5): ";
		cin >> menu;
		if (menu < 1 || menu > 5) continue;
		switch (menu) {
		case 1: cout << "Size: " << diary.getsize(list) << endl; break;
		case 2: add(diary, list, iter); break;
		case 3: read(diary, list); break;
		case 4: write(diary, list); break;
		case 5: break;
		}
	} while (menu != 5);

	return 0;
}