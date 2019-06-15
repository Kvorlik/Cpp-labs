//������� 11.
//1. ���������� ���������� ������� �6, �� � �������� �������� ������ ����������� ��������������� ���������.
//2. ������������� ���������� �����������.

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
			cout << "* ������ ����������� ������ Day ��� " << this << endl;
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
		cout << "* ������ ���������� ������� ������ Day ��� " << this << endl;
	}
	Day(const Day& other) {
		try {
			cout << "* ������ ����������� ����������� ������ Day ��� " << this << endl;
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
			cout << "* ������ �������� ������������ ������ Day ��� " << this << " � " << &other << endl;
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
			int daynumber = 0; //����� ��� � ����
			for (int i = 1; i < m + 1; i++) {
				if (i == 2) {
					if (i == m) {
						daynumber = daynumber + d;
					}
					else {
						daynumber = daynumber + 28; //�������
						continue;
					}
				}
				if (i == 8) {
					if (i == m) {
						daynumber = daynumber + d;
					}
					else {
						daynumber = daynumber + 31; //������
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
			case 1: week_day = "�����������"; break;
			case 2: week_day = "�������"; break;
			case 3: week_day = "�����"; break;
			case 4: week_day = "�������"; break;
			case 5: week_day = "�������"; break;
			case 6: week_day = "�������"; break;
			case 0: week_day = "�����������"; break;
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
					cout << "������ �������." << endl
						<< "���� �� " << d << "." << m << ".2018, " << it->week_day << ":" << endl
						<< it->objective << endl;
					return;
				}
				else it++;
			}
			cout << "������ �� �������." << endl;
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
					cout << "������ ��������." << endl;
					return;
				}
				else it++;
			}
			cout << "������ �� �������." << endl;
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