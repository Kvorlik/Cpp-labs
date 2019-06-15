#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "file.cpp"
using namespace std;

char **create() {
	char **buff = new char *[10];
	for (int i = 0; i < 10; i++) {
		buff[i] = new char[256];
	}
	return buff;
}
void erase(char **buff) {
	for (int i = 0; i < 10; i++) {
		delete[] buff[i];
	}
	delete[] buff;
}

int main() {
	setlocale(LC_ALL, "rus");
	Myfile f;
	char* filename = new char[20];
	char** buffer = create();
	cout << "Введите название txt файла: ";
	cin >> filename;
	f.set_name(filename);
	cout << "Чтение файла " << filename << ".txt ..." << endl;
	if (f.open_txt() == 1) {
		system("pause");
		return 1;
	}
	cout << "Создание файла " << filename << ".dat ..." << endl;
	if (f.create_dat() == 2) {
		system("pause");
		return 2;
	}
	cout << "Копирование из " << filename << ".txt в " << filename << ".dat ..." << endl;
	f.copy(buffer);
	cout << "Закрытие " << filename << ".txt и " << filename << ".dat ..." << endl;
	f.close();
	erase(buffer);
	delete[] filename;
	system("pause");
	return 0;
}