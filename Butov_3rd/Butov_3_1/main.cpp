#include <iostream>
#include <locale>
#include "stack.cpp"
using namespace std;

int stackpush(Stack& newstack) {
	int data;
	cout << "������� �����: ";
	cin >> data;
	newstack << data;
	return 0;
}

int stackpop(Stack& newstack) {
	int data = NULL;
	data = newstack >> data;
	if (data == NULL) return 1;
	else cout << "��������� data ����� �������� �� �����. data = " << data << endl;
	return 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	unsigned int size = 0;
	int pop = 0;

	cout << "������� ������ �����: ";
	cin >> size;
	Stack newstack(size);
	system("pause");

	int menu;
	do {
		system("cls");
		cout << "����:" << endl << "1) �������� ����." << endl << "2) �������� �� ����." << endl << "3) ����� �� �����." << endl << "4) ����� �� ���������." << endl << "�������� �������: ";
		cin >> menu;
		if (menu < 1 || menu > 4) continue;
		switch (menu) {
		case 1: newstack.show(); system("pause"); break;
		case 2: stackpush(newstack); system("pause"); break;
		case 3: stackpop(newstack); system("pause"); break;
		case 4: break;
		}
	} while (menu != 4);

	system("pause");
	return 0;
}