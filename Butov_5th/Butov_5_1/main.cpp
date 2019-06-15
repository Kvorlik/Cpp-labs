#include <string>
#include <iostream>
#include <locale>
#include "stack.cpp"
using namespace std;

template <typename T> void stackpush(Stack<T>& stackname) {
	T data;
	cout << "������� ������: ";
	cin >> data;
	stackname << data;
}
template <typename T> void stackpop(Stack<T>& stackname) {
	T data;
	data = stackname >> 1;
	cout << "��������� data ����� �������� �� �����. data = " << data << endl;
}
template <typename T> void menu(Stack<T>& stackname){
	int menu;
	do {
		system("cls");
		cout << "����:" << endl << "1) �������� ����." << endl << "2) �������� �� ����." << endl << "3) ����� �� �����." << endl << "4) ���������� ����." << endl << "�������� �������: ";
		cin >> menu;
		if (menu < 1 || menu > 4) continue;
		switch (menu) {
		case 1: stackname.show(); system("pause"); break;
		case 2: stackpush(stackname); system("pause"); break;
		case 3: stackpop(stackname); system("pause"); break;
		case 4: break;
		}
	} while (menu != 4);
}

template <typename T> void sstackpush(StringStack<T>& stackname) {
	T data;
	cout << "������� ������: ";
	cin >> data;
	stackname << data;
}
template <typename T> void sstackpop(StringStack<T>& stackname) {
	T data;
	data = stackname >> 1;
	cout << "��������� data ����� �������� �� �����. data = " << data << endl;
}
template <typename T> void smenu(StringStack<T>& stackname) {
	int menu;
	do {
		system("cls");
		cout << "����:" << endl << "1) �������� ����." << endl << "2) �������� �� ����." << endl << "3) ����� �� �����." << endl << "4) ���������� ����." << endl << "�������� �������: ";
		cin >> menu;
		if (menu < 1 || menu > 4) continue;
		switch (menu) {
		case 1: stackname.show(); system("pause"); break;
		case 2: sstackpush(stackname); system("pause"); break;
		case 3: sstackpop(stackname); system("pause"); break;
		case 4: break;
		}
	} while (menu != 4);
}

int main() {
	setlocale(LC_ALL, "rus");
	unsigned int size = 0;
	int pop = 0;

	cout << "------[ ������������ ��������������� ��� T = int ]------" << endl;
	cout << "������� ������ �����: ";
	cin >> size;
	Stack<int> intstack(size);
	system("pause");
	menu(intstack);

	system("cls");

	cout << "------[ ������������ ��������������� ��� T = float ]------" << endl;
	cout << "������� ������ �����: ";
	cin >> size;
	Stack<float> floatstack(size);
	system("pause");
	menu(floatstack);

	system("cls");

	cout << "------[ ������������ ��������������� ��� T = string ]------" << endl;
	cout << "������� ������ �����: ";
	cin >> size;
	StringStack<string> stringstack(size, 1);
	system("pause");
	smenu(stringstack);

	//����������� ���������� ���������� ��� ����� �������������� ������� �����

	system("pause");
	return 0;
}