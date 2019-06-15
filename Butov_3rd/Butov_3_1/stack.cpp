#include <iostream>
using namespace std;

class Stack {
private:
	int top;
	int stack_size;
	int* stack;
public:
	Stack(int size) {
		cout << "* ������ ����������� ������� " << this << " ������ Stack." << endl;
		top = -1;
		stack_size = size;
		stack = new int[stack_size];
		for (int i = 0; i < stack_size; i++) {
			stack[i] = NULL;
		}
	}
	~Stack() {
		cout << "* ������ ���������� ������� " << this << " ������ Stack." << endl;
		delete[] stack;
	}
	void operator << (int data) {
		cout << "* ������ �������� push." << endl;
		if (top == stack_size - 1) {
			cout << "������������� ������������ �����. �������� �� ���������." << endl;
			return;
		}
		top++;
		stack[top] = data;
	}
	int operator >> (int) {
		int temp = 0;
		cout << "* ������ �������� pop." << endl;
		if (top < 0) {
			cout << "���� ����. �������� �� ���������." << endl;
			return NULL;
		}
		temp = stack[top];
		stack[top] = NULL;
		top--;
		return temp;
	}
	void show() {
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
};