#include <iostream>
#include <locale>
#include <forward_list>
#include "module.cpp"
using namespace std;

void add(Day& diary, forward_list<Day>& list, forward_list<Day>::iterator& iter) {
	int d, m;
	string obj;
	cout << "Введите число: ";			cin >> d;
	cout << "Введите месяц: ";			cin >> m;
	cout << "Напишите список дел: ";	cin >> obj;
	diary.add(d, m, obj, list, iter);
}
void read(Day& diary, forward_list<Day>& list) {
	int d, m;
	cout << "Введите число: "; cin >> d;
	cout << "Введите месяц: "; cin >> m;
	diary.read(d, m, list);
}
void write(Day& diary, forward_list<Day>& list) {
	int d, m;
	string obj;
	cout << "Введите число: ";			cin >> d;
	cout << "Введите месяц: ";			cin >> m;
	cout << "Напишите список дел: ";	cin >> obj;
	diary.write(d, m, obj, list);
}

int main() {
	setlocale(LC_ALL, "rus");
	int d, m;
	string buffer;
	forward_list<Day> list;
	forward_list<Day>::iterator iter;

	cout << "Создание списка." << endl;
	cout << "Введите число: ";			cin >> d;
	cout << "Введите месяц: ";			cin >> m;
	cout << "Напишите список дел: ";	cin >> buffer;
	Day diary(d, m, buffer);
	list.push_front(diary);
	iter = list.begin();

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
		case 1: cout << "Size: " << diary.getsize(list) << endl; break;
		case 2: add(diary, list, iter); break;
		case 3: read(diary, list); break;
		case 4: write(diary, list); break;
		case 5: break;
		}
	} while (menu != 5);

	return 0;
}