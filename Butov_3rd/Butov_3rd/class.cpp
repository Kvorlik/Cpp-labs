#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "class.h"
using namespace std;

inline Table::Table() {
	cout << "* Вызван конструктор для " << this << endl;
	name = new char[20];
	place = new char[20];
	group = new char[20];
	memset(name, 0, sizeof(name));
	memset(place, 0, sizeof(place));
	memset(group, 0, sizeof(group));
	count = 0;
}
inline Table::Table(const Table& other) {
	cout << "* Вызван конструктор копирования для " << this << endl;
	name = new char[20];
	place = new char[20];
	group = new char[20];
	memset(name, 0, sizeof(name));
	memset(place, 0, sizeof(place));
	memset(group, 0, sizeof(group));
	count = 0;
	strcpy(name, other.name);
	strcpy(group, other.group);
	strcpy(place, other.place);
	count = other.count;
}
inline Table::~Table() {
	cout << "* Вызван деструктор для " << this << endl;
	delete[] name;
	delete[] place;
	delete[] group;
}
inline char* Table::get_name() { return name; }
inline char* Table::get_group() { return group; }
inline char* Table::get_place() { return place; }
inline int  Table::get_count() { return count; }
inline void Table::set_name(char* source) {
	strcpy(name, source);
}
inline void Table::set_group(char* source) {
	strcpy(group, source);
}
inline void Table::set_place(char* source) {
	strcpy(place, source);
}
inline void Table::set_count() {
	cout << "Введите численность популяции: ";
	cin >> count;
}
inline void Table::show() {
	cout << get_name() << "\t\t" << get_group() << "\t" << get_place() << "\t\t" << get_count() << endl;
}
inline int Table::operator == (const Table& other) {
	cout << "* Вызван оператор соответствия для " << this << " и " << &other << endl;
	if ((strcmp(name, other.name) != 0) || (strcmp(group, other.group) != 0) ||
		(strcmp(place, other.place) != 0) || (count != other.count))
		return 0;
	else
		return 1;
}
inline Table& Table::operator = (const Table& other) {
	cout << "* Вызван оператор присваивания для " << this << " и " << &other << endl;
	strcpy(name, other.name);
	strcpy(group, other.name);
	strcpy(place, other.name);
	count = other.count;
	return *this;
}