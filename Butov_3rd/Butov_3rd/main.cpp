#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "class.cpp"
using namespace std;

Table operator + (const Table& a, const Table& b) {
	cout << "* Вызван оператор сложения для " << &a << " и " << &b << endl;
	Table temp;
	strcat(temp.name, a.name);
	strcat(temp.name, " и ");
	strcat(temp.name, b.name);
	strcat(temp.group, a.group);
	strcat(temp.group, " и ");
	strcat(temp.group, b.group);
	strcat(temp.place, a.place);
	strcat(temp.place, " и ");
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

	cout << "Текущее состояние таблицы \"Некоторые виды антилоп\"" << endl
		<< "Название\tГруппа\tМесто обитания\tЧисленность популяции" << endl;
	string1.show();
	string2.show();
	string3.show();
	system("pause");
	system("cls");

	cout << "Заполнение таблицы." << endl
		<< "Элементы первый строки:" << endl
		<< "Введите название: ";
	cin >> buffer;
	string1.set_name(buffer);
	cout << "Введите группу: ";
	cin >> buffer;
	string1.set_group(buffer);
	cout << "Введите место обитания: ";
	cin >> buffer;
	string1.set_place(buffer);
	string1.set_count();
	cout << "Элементы второй строки:" << endl;
	cout << "Введите название: ";
	cin >> buffer;
	string2.set_name(buffer);
	cout << "Введите группу: ";
	cin >> buffer;
	string2.set_group(buffer);
	cout << "Введите место обитания: ";
	cin >> buffer;
	string2.set_place(buffer);
	string2.set_count();
	cout << "Элементы третьей строки:" << endl;
	cout << "Введите название: ";
	cin >> buffer;
	string3.set_name(buffer);
	cout << "Введите группу: ";
	cin >> buffer;
	string3.set_group(buffer);
	cout << "Введите место обитания: ";
	cin >> buffer;
	string3.set_place(buffer);
	string3.set_count();
	system("pause");
	system("cls");

	cout << "Текущее состояние таблицы \"Некоторые виды антилоп\"" << endl
		<< "Название\tГруппа\tМесто обитания\tЧисленность популяции" << endl;
	string1.show();
	string2.show();
	string3.show();

//Задание 4:
	cout << "Выполняется проверка на соответствие первой и второй строк... " << endl;
	if (string1 == string2) cout << "Строки одинаковые." << endl;
	else cout << "Строки разные" << endl;
	cout << "Выполняется сложение первой и второй строк..." << endl;
	Table string4 = string1 + string2;
	cout << "Выполнено." << endl;
	system("pause");
	system("cls");

	cout << "Текущее состояние таблицы \"Некоторые виды антилоп\"" << endl
		<< "Название\tГруппа\tМесто обитания\tЧисленность популяции" << endl;
	string1.show();
	string2.show();
	string3.show();
	string4.show();

	delete[] buffer;
	system("pause");
	return 0;
}