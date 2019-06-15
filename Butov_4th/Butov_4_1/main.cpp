#include <iostream>
#include <locale>
#include "class.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	cout << "ƒемонстраци€ иерархии класса согласно схеме наследовани€, приведенной в 1 варианте задани€." << endl;
	D3 demo;
	cout << endl << "—леду€ иерархии класса D3:" << endl;
	demo.showD3();

	system("pause");
	return 0;
}