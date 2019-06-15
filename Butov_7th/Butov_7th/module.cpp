//Задание 11.
//1. Реализуйте функционал задания №6, но в качестве базового класса используйте соответствующий контейнер.
//2. Использование итераторов обязательно.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <forward_list>
#include <locale>
using namespace std;

class Day {
private:
	int date;
	int month;
	string week_day;
	string objective;
public:
	Day(int d, int m, string obj) {
		try {
			cout << "* Вызван конструктор класса Day для " << this << endl;
			date = d;
			month = m;
			getday(d, m);
			objective = obj;
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	~Day() {
		cout << "* Вызван деструктор объекта класса Day для " << this << endl;
	}
	Day(const Day& other) {
		try {
			cout << "* Вызван конструктор копирования класса Day для " << this << endl;
			date = other.date;
			month = other.month;
			week_day = other.week_day;
			objective = other.objective;
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	Day& operator = (const Day& other) {
		try {
			cout << "* Вызван оператор присваивания класса Day для " << this << " и " << &other << endl;
			date = other.date;
			month = other.month;
			week_day = other.week_day;
			objective = other.objective;
			return *this;
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	void getday(int d, int m) {
		try {
			int daynumber = 0; //Номер дня в году
			for (int i = 1; i < m + 1; i++) {
				if (i == 2) {
					if (i == m) {
						daynumber = daynumber + d;
					}
					else {
						daynumber = daynumber + 28; //Февраль
						continue;
					}
				}
				if (i == 8) {
					if (i == m) {
						daynumber = daynumber + d;
					}
					else {
						daynumber = daynumber + 31; //Август
						continue;
					}
				}
				int temp = i % 2;
				if (temp == 0) {
					if (i == m) {
						daynumber = daynumber + d;
					}
					else {
						daynumber = daynumber + 30;
						if (i > 8) daynumber++;
					}
				}
				else {
					if (i == m) {
						daynumber = daynumber + d;
					}
					else {
						daynumber = daynumber + 31;
						if (i > 8) daynumber--;
					}
				}
			}

			int DOW = daynumber % 7;; // DOW - Day of week
			switch (DOW) {
			case 1: week_day = "Понедельник"; break;
			case 2: week_day = "Вторник"; break;
			case 3: week_day = "Среда"; break;
			case 4: week_day = "Четверг"; break;
			case 5: week_day = "Пятница"; break;
			case 6: week_day = "Суббота"; break;
			case 0: week_day = "Воскресенье"; break;
			}
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	void add(int d, int m, string obj, forward_list<Day>& list, forward_list<Day>::iterator& iter) {
		try {
			list.emplace_after(iter, Day(d, m, obj));
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	void read(int d, int m, forward_list<Day>& list) {
		try {
			int success = 0;
			forward_list<Day>::iterator it = list.begin();
			while (it != list.end() && success != 1) {
				if (it->date == d && it->month == m) {
					success = 1;
					cout << "Запись найдена." << endl
						<< "Дела на " << d << "." << m << ".2018, " << it->week_day << ":" << endl
						<< it->objective << endl;
					return;
				}
				else it++;
			}
			cout << "Запись не найдена." << endl;
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	void write(int d, int m, string obj, forward_list<Day>& list) {
		try {
			int success = 0;
			forward_list<Day>::iterator it = list.begin();
			while (it != list.end() && success != 1) {
				if (it->date == d && it->month == m) {
					success = 1;
					it->objective = obj;
					cout << "Запись изменена." << endl;
					return;
				}
				else it++;
			}
			cout << "Запись не найдена." << endl;
		}
		catch (exception& ex) {
			ex.what();
		}
	}
	int getsize(forward_list<Day>& list) {
		try {
			int size = 0;
			for (forward_list<Day>::iterator it = list.begin(); it != list.end(); it++) size++;
			return size;
		}
		catch (exception& ex) {
			ex.what();
			return 0;
		}
	}
};