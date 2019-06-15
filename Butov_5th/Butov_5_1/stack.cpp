#include <iostream>
#include <string>
#include <exception>

using namespace std;

template <typename T>
class Stack {
public:
	int top;
	int stack_size;
	T* stack;
	Stack(int size) {
		try {
			cout << "* ������ ����������� ������� " << this << " ������ Stack." << endl;
			top = -1;
			stack_size = size;
			stack = new T[stack_size];
			for (int i = 0; i < stack_size; i++) {
				stack[i] = NULL;
			}
		}
		catch (...) { cout << "������. ������������� ������ �����." << endl; }
	}
	Stack(int size, int IsString) {
		try {
			cout << "* ������ ����������� ������� " << this << " ������ Stack." << endl;
			top = -1;
			stack_size = size;
			stack = new T[stack_size];
		}
		catch (...) { cout << "������. ������������� ������ �����." << endl; }
	}
	~Stack() {
		cout << "* ������ ���������� ������� " << this << " ������ Stack." << endl;
		delete[] stack;
	}
	void operator << (T data) {
		try {
			if (!stack) throw 1;
			cout << "* ������ �������� push." << endl;
			if (top == stack_size - 1) {
				cout << "������������� ������������ �����. �������� �� ���������." << endl;
				return;
			}
			top++;
			stack[top] = data;
		}
		catch (...) { cout << "������. ����� �� ����������." << endl; }
	}
	T operator >> (int) {
		try {
			if (!stack) throw 1;
			cout << "* ������ �������� pop." << endl;
			T temp;
			if (top < 0) {
				cout << "���� ����. �������� �� ���������." << endl;
				return NULL;
			}
			temp = stack[top];
			stack[top] = '\0';
			top--;
			return temp;
		}
		catch (...) { cout << "������. ����� �� ����������." << endl; return NULL; }
	}
	void show() {
		try {
			if (!stack) throw 1;
			cout << "��������� �����:" << endl;
			if (stack[0] == NULL) {
				cout << "���� ����." << endl;
				return;
			}
			for (int i = stack_size - 1; i >= 0; i--) {
				if (stack[i] != NULL) {
					cout << i + 1 << ") " << stack[i] << endl;
				}
			}
		}
		catch (...) { cout << "������. ����� �� ����������." << endl; }
	}
};

template <typename T>
class StringStack : public Stack<T> {
public:
	StringStack(int size, int IsString) : Stack<T>::Stack(size, IsString) {
		cout << "* ������ ����������� ������� " << this << " ������ StringStack." << endl;
	}
	~StringStack() {
		cout << "* ������ ���������� ������� " << this << " ������ StringStack." << endl;
	}
	void operator << (T data) {
		try {
			if (!Stack<T>::stack) throw 1;
			cout << "* ������ �������� push." << endl;
			if (Stack<T>::top == Stack<T>::stack_size - 1) {
				cout << "������������� ������������ �����. �������� �� ���������." << endl;
				return;
			}
			Stack<T>::top++;
			Stack<T>::stack[Stack<T>::top] = data;
		}
		catch (...) { cout << "������. ����� �� ����������." << endl; }
	}
	T operator >> (int) {
		try {
			if (!Stack<T>::stack) throw 1;
			cout << "* ������ �������� pop." << endl;
			T temp;
			if (Stack<T>::top < 0) {
				cout << "���� ����. �������� �� ���������." << endl;
				return NULL;
			}
			temp = Stack<T>::stack[Stack<T>::top];
			Stack<T>::stack[Stack<T>::top] = '\0';
			Stack<T>::top--;
			return temp;
		}
		catch (...) { cout << "������. ����� �� ����������." << endl; return NULL; }
	}
	void show() {
		try {
			if (!Stack<T>::stack) throw 1;
			cout << "��������� �����:" << endl;
			if (Stack<T>::stack[0].empty()) {
				cout << "���� ����." << endl;
				return;
			}
			for (int i = Stack<T>::stack_size - 1; i >= 0; i--) {
				if (!Stack<T>::stack[i].empty()) {
					cout << i + 1 << ") " << Stack<T>::stack[i] << endl;
				}
			}
		}
		catch (...) { cout << "������. ����� �� ����������." << endl; }
	}
};