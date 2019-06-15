#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
using namespace std;

class List {
private:
	int size;
	struct elem {
		void* data;
		elem* pNext;
	};
	elem element;
	elem* head;
	elem* curr;
public:
	List() {
		cout << "* ������ ����������� ������� ������ List ��� " << this << endl;
		size = 0;
		element.data = nullptr;
		element.pNext = nullptr;
		if (size == 0) {
			head = &element;
			size++;
		}
		curr = head;
	}
	~List() {
		cout << "* ������ ���������� ������� ������ List ��� " << this << endl;
	}
	List(const List& other) {
		cout << "* ������ ����������� ����������� ������� ������ List ��� " << this << " � " << &other << endl;
		size = other.size;
		element.data = other.element.data;
		element.pNext = other.element.pNext;
		head = other.head;
		curr = other.curr;
	}
	List& operator = (const List& other) {
		cout << "* ������ �������� ������������ ������� ������ List ��� " << this << " � " << &other << endl;
		size = other.size;
		element.data = other.element.data;
		element.pNext = other.element.pNext;
		head = other.head;
		curr = other.curr;
		return *this;
	}
	void incsize() { size++; }
	int getsize() { return size; }
	elem* gethead() { return head; }
	elem* getcurr() { return curr; }
	elem* getnext() { return element.pNext; }
	elem* getelement() { return &element; }
	void* getptr() { return curr->data; }
	void setbegin() { curr = head; }
	void forward() { curr = curr->pNext; }
	void sethead(elem* const newhead) { head = newhead; }
	void setpnext(elem* const newpnext) { curr->pNext = newpnext; }
	void setdata(void* newdata) { element.data = newdata;	}
};

class Day : public List {
private:
	struct Data {
		int date;
		int month;
		char* week_day;
		char* objective;
	};
	Data current;
public:
	Day(int d, int m, char* obj) {
		cout << "* ������ ����������� ������ Day ��� " << this << endl;
		setdata(&current);
		current.date = d;
		current.month = m;
		current.week_day = new char[12];
		getday(d, m);
		current.objective = new char[256];
		strcpy(current.objective, obj);
	}
	~Day() {
		cout << "* ������ ���������� ������� ������ Day ��� " << this << endl;
		if (current.week_day) delete[] current.week_day;
		if (current.objective) delete[] current.objective;
	}
	Day(const Day& other) {
		cout << "* ������ ����������� ����������� ������ Day ��� " << this << endl;
		current.week_day = new char[256];
		current.objective = new char[256];
		current.date = other.current.date;
		current.month = other.current.month;
		strcpy(current.week_day, other.current.week_day);
		strcpy(current.objective, other.current.objective);
	}
	Day& operator = (const Day& other) {
		cout << "* ������ �������� ������������ ������ Day ��� " << this << " � " << &other << endl;
		current.date = other.current.date;
		current.month = other.current.month;
		strcpy(current.week_day, other.current.week_day);
		strcpy(current.objective, other.current.objective);
		return *this;
	}
	void getday(int d, int m) {
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
		
		int DOW = daynumber % 7;; //Day of week
		switch (DOW) {
		case 1: strcpy(current.week_day, "�����������"); break;
		case 2: strcpy(current.week_day, "�������"); break;
		case 3: strcpy(current.week_day, "�����"); break;
		case 4: strcpy(current.week_day, "�������"); break;
		case 5: strcpy(current.week_day, "�������"); break;
		case 6: strcpy(current.week_day, "�������"); break;
		case 0: strcpy(current.week_day, "�����������"); break;
		}
	}
	void add(int d, int m, char* obj) {
		Day* tmp = new Day(d, m, obj);
		setbegin();
		while (getnext() != nullptr) {
			forward();
		}
		setpnext(tmp->getelement());
		incsize();
	}
	void read(int d, int m) {
		setbegin();
		int success = 0;
		Data* tmp;
		while (getcurr() != nullptr && success != 1) {
			tmp = static_cast<Data*>(getptr());
			if (tmp->date == d && tmp->month == m) {
				success = 1;
				cout << "������ �������." << endl
					<< "���� �� " << d << "." << m << ".2018, " << tmp->week_day << ":" << endl
					<< tmp->objective << endl;
				return;
			}
			else forward();
		}
		if (getcurr() == NULL || getnext() == nullptr) {
			cout << "������ �� �������." << endl;
		}
	}
	void write(int d, int m, char* obj) {
		setbegin();
		int success = 0;
		Data* tmp;
		while (getcurr() != nullptr && success != 1) {
			tmp = static_cast<Data*>(getptr());
			if (tmp->date == d && tmp->month == m) {
				success = 1;
				strcpy(tmp->objective, obj);
				cout << "������ ��������." << endl;
				return;
			}
			else forward();
		}
		if (getcurr() == NULL || getnext() == nullptr) {
			cout << "������ �� �������." << endl;
		}
	}
};