#include <iostream>
#include <locale>
#include "class.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	cout << "������������ �������� ������ �������� ����� ������������, ����������� � 1 �������� �������." << endl;
	D3 demo;
	cout << endl << "������ �������� ������ D3:" << endl;
	demo.showD3();

	system("pause");
	return 0;
}