#include <iostream>
#include <locale>
#include <stdexcept>
#include "class.h"
using namespace std;

inline CreateException::CreateException() : runtime_error("Ошибка: отрицательная длина строки или выход за её границы") {}

template <typename T> Array<T>::Array(int size, const T* str) {
	cout << "Вызван конструктор класса Array " << this << endl;
	try {
		int temp = strlen(str) + 1;
		if (size < 1 || size < temp) {
			throw CreateException();
		}
		strng = new T[size + 1];
		strcpy(strng, str);
		ptr = strng;
		count = size;
	}
	catch (CreateException& ex) {
		cout << ex.what() << endl;

	}
}
template <typename T> Array<T>::~Array() {
	cout << "Вызван деструктор класса Array " << this << endl;
	delete[] strng;
}
template <typename T> Array<T>::Array(const Array& other) {
	try {
		int temp = strlen(other.strng) + 1;
		if (other.count < 1 || other.count < temp) {
			throw CreateException();
		}
		count = other.count;
		strng = new T[other.count + 1];
		strcpy(strng, other.strng);
		ptr = strng;
	}
	catch (CreateException& ex) {
		cout << ex.what() << endl;
	}
}
template <typename T> void Array<T>::setstring(T* str) {
	strcpy(strng, str);
}
template <typename T> T* Array<T>::getptr() {
	return ptr;
}
template <typename T> int Array<T>::getcount() {
	return count;
}
template <typename T> void Array<T>::change() {
	cout << "Вызвана функция базового класса." << endl;
}

template <typename T> MyString<T>::MyString(int size, const T* str) : Array<T>::Array(size, str) {
	cout << "Вызван конструктор класса MyString " << this << endl;
	change();
}
template <typename T> MyString<T>::~MyString() {
	cout << "Вызван деструктор класса MyString " << this << endl;
}
template <typename T> void MyString<T>::change() {
	cout << "Вызвана функция изменения регистра букв." << endl;
	try {
		T* temp = Array<T>::getptr();
		if (temp == 0) {
			throw 1;
		}
		int tmpcnt = Array<T>::getcount();
		T* tmpstr = new T[tmpcnt + 1];
		T* tmpptr = Array<T>::getptr();
		strcpy(tmpstr, tmpptr);
		for (int i = 0; i < tmpcnt; i++) {
			tmpstr[i] = toupper(tmpstr[i]);
		}
		Array<T>::setstring(tmpstr);
		cout << "Результат: " << tmpptr << endl;
		delete[] tmpstr;
	}
	catch (int) {
		cout << "Функция не выполнена." << endl;
	}
}