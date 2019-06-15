#include <iostream>
#include <locale>
using namespace std;

class B {
private:
	int dataB;
public:
	B() {
		cout << "* Вызван конструктор B." << endl;
		dataB = 0;
	}
	void showB() {
		cout << "dataB: " << dataB << endl;
	}
};

class D1 : public B {
private:
	int dataD1;
public:
	D1() : B() {
		cout << "* Вызван конструктор D1." << endl;
		dataD1 = 1;
	}
	void showD1() {
		cout << "dataD1: " << dataD1 << endl;
		showB();
	}
};

class D2 : private B {
private:
	int dataD2;
public:
	D2() : B() {
		cout << "* Вызван конструктор D2." << endl;
		dataD2 = 2;
	}
	void showD2() {
		cout << "dataD2: " << dataD2 << endl;
		showB();
	}
};

class D3 : public D1, private D2 {
private:
	int dataD3;
public:
	D3() : D1(), D2() {
		cout << "* Вызван конструктор D3." << endl;
		dataD3 = 3;
	}
	void showD3() {
		cout << "dataD3: " << dataD3 << endl;
		showD1();
		showD2();
	}
};