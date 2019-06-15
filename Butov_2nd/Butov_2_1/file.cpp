#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "file.h"
using namespace std;

inline Myfile::Myfile() {
	name = new char[20];
	txtname = new char[20];
	datname = new char[20];
	txt = 0;
	dat = 0;
}
inline Myfile::~Myfile() {
	delete[] name;
	delete[] txtname;
	delete[] datname;
}
inline void Myfile::set_name(char *filename) {
	strcpy(name, filename);
	strcpy(txtname, name);
	strcat(txtname, ".txt");
	strcpy(datname, name);
	strcat(datname, ".dat");
}
inline int Myfile::open_txt() {
	txt = fopen(txtname, "r");
	if (txt == NULL) {
		cout << "Ошибка чтения файла." << endl;
		fclose(txt);
		return 1;
	}
	else {
		cout << txtname << " прочитан." << endl;
		return 0;
	}
}
inline int Myfile::create_dat() {
	dat = fopen(datname, "w");
	if (dat == NULL) {
		cout << "Ошибка создания файла." << endl;
		fclose(dat);
		return 2;
	}
	else {
		cout << datname << " создан." << endl;
		return 0;
	}
}
inline void Myfile::copy(char** buf) {
	for (int i = 0; i < 10; i++){
		fscanf(txt, "%s", buf[i]);
	}

	char* temp = new char[256];
	temp = 0;
	for (int k = 0; k < 10; k++) {
		for (int a = 9; a > 1; a--) {
			for (int i = 0; i < a; i++) {
				if (strcmp(buf[i], buf[i + 1]) > 0) {
					temp = buf[i];
					buf[i] = buf[i + 1];
					buf[i + 1] = temp;
					temp = 0;
				}
			}
		}
	}
	delete[] temp;

	for (int i = 0; i < 10; i++) {
		fprintf(dat, "%s\n", buf[i]);
	}
	cout << "Данные скопированы." << endl;
}
inline void Myfile::close() {
	fclose(txt);
	fclose(dat);
	cout << "Файлы закрыты." << endl;
}