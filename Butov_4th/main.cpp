#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "class.cpp"
using namespace std;

void add(Day& diary) {
	int d, m;
	char* obj = new char[256];
	cout << "Введите число: ";			cin >> d;
	cout << "Введите месяц: ";			cin >> m;
	cout << "Напишите список дел: ";	cin >> obj;
	diary.add(d, m, obj);
	delete[] obj;
}
void read(Day& diary) {
	int d, m;
	cout << "Введите число: "; cin >> d;
	cout << "Введите месяц: "; cin >> m;
	diary.read(d, m);
}
void write(Day& diary) {
	int d, m;
	char* obj = new char[256];
	cout << "Введите число: ";			cin >> d;
	cout << "Введите месяц: ";			cin >> m;
	cout << "Напишите список дел: ";	cin >> obj;
	diary.write(d, m, obj);
	delete[] obj;
}

int main() {
	setlocale(LC_ALL, "rus");
	int d, m;
	char* buffer = new char[256];

	cout << "Создание списка." << endl;
	cout << "Введите число: ";			cin >> d;
	cout << "Введите месяц: ";			cin >> m;
	cout << "Напишите список дел: ";	cin >> buffer;
	Day diary(d, m, buffer);

	int menu = 0;
	do {
		system("pause");
		system("cls");
		cout << "1) Показать кол-во записей списка." << endl
			<< "2) Добавить запись." << endl
			<< "3) Прочитать список дел на день." << endl
			<< "4) Изменить список дел на день." << endl
			<< "5) Выйти из программы." << endl
			<< "Выберите действие (1-5): ";
		cin >> menu;
		if (menu < 1 || menu > 5) continue;
		switch (menu) {
		case 1: cout << "Size: " << diary.getsize() << endl; break;
		case 2: add(diary); break;
		case 3: read(diary); break;
		case 4: write(diary); break;
		case 5: break;
		}
	} while (menu != 5);

	return 0;
}