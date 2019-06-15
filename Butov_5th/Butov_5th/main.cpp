#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <stdexcept>
#include "class.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	MyString<char> a(10, "AnyString");
	cout << "--------------------------------------------------" << endl;
	MyString<char> b(1, "AnyString");
	cout << "--------------------------------------------------" << endl;
	MyString<char> c(-1, "AnyString");
	cout << "--------------------------------------------------" << endl;

	system("pause");
	return 0;
}