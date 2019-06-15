#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "class.h"
using namespace std;

inline Table::Table() {
	name = new char[20];
	place = new char[20];
	memset(name, 0, sizeof(name));
	memset(place, 0, sizeof(place));
	group = 0;
	count = 0;
}
inline Table::~Table() {
	delete[] name;
	delete[] place;
}
inline char* Table::get_name()  {return name;}
inline char Table::get_group() {return group;}
inline char* Table::get_place() {return place;}
inline int  Table::get_count() {return count;}
inline void Table::set_name(char* source) {
	strcpy(name, source);
}
inline void Table::set_group() {
	cout << "¬ведите группу: ";
	cin >> group;
}
inline void Table::set_place(char* source) {
	strcpy(place, source);
}
inline void Table::set_count() {
	cout << "¬ведите численность попул€ции: ";
	cin >> count;
}
inline void Table::show() {
	cout << get_name() << "\t\t" << get_group() << "\t" << get_place() << "\t\t" << get_count() << endl;
}