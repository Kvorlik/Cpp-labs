#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "main.h"
using namespace std;

//�������� ������������ ��������� �������
char **create(int n, int m) {
	char **matrix = new char *[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new char[m];
	}
	return matrix;
}
//������������ ������
void erase(int n, char **matrix) {
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
//�������� �����
int check_file(char* name) {
	char temp[1];
	FILE *f = fopen(name, "r");
	if (f == NULL) {
		cout << "�� ������� ������� ����." << endl;
		fclose(f);
		return 1;
	}
	if ((fscanf(f, "%c", &temp)) != 1) {
		cout << "�� ������� ��������� ����." << endl;
		fclose(f);
		return 2;
	}
	fclose(f);
	return 3;
}
//������ �� ����� � �������
void read(int n, int m, char **matrix, char *name) {
	FILE *f = fopen(name, "r");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(f, "%c", &matrix[i][j]);
		}
	}
	fclose(f);
}
//������ ������� � �������
void print(int n, int m, char **matrix) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << " " << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
//���������� ������� � ����
void save(int n, int m, char **matrix, char *name) {
	FILE *f = fopen(name, "w");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(f, "%c", matrix[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 3;
	int m = 6;
	int way = 0;
	char **matr = 0;
	char source[20];
	char destination[20];

	cout << "������� �������� �����-���������: ";
	cin >> source;
	cout << "������ ����� " << source << "..." << endl;
	switch (check_file(source)) {
	case 1: return 1; break;
	case 2: return 2; break;
	case 3: cout << "�������." << endl; break;
	}
	matr = create(n, m);
	read(n, m, matr, source);
	print(n, m, matr);

	cout << "����� ������ ������������?" << endl
		<< "1) ���������� �������" << endl
		<< "2) ���������� �������" << endl
		<< "������� ����� (1/2): ";
	cin >> way;
	switch (way) {
	case 1: sort_by_choice(n, m, matr); print(n, m, matr); break;
	case 2: sort_by_exchange(n, m, matr); print(n, m, matr); break;
	}

	cout << "��������� ��������� � ����?" << endl
		<< "1) ��" << endl
		<< "2) ���" << endl
		<< "������� ����� (1/2): ";
	cin >> way;
	if (way == 1) {
		cout << "�������� ����: ";
		cin >> destination;
		save(n, m, matr, destination);
	}

	cout << "������������ ������..." << endl;
	erase(n, matr);
	system("pause");
	return 0;
}