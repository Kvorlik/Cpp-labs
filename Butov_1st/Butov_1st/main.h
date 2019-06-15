#include <iostream>
#include <locale>
using namespace std;

void sort_by_choice(int n, int m, char **matrix) {
	int checks = 0;
	int exchanges = 0;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			temp = matrix[i][j];
			for (int t = j + 1; t < m; t++) {
				checks++;
				if (matrix[i][t] < temp) {
					temp = matrix[i][t];
					matrix[i][t] = matrix[i][j];
					matrix[i][j] = temp;
					exchanges++;
				}
			}
		}
	}
	cout << endl << "Сортировка завершена." << endl
		<< "Сравнений выполнено: " << checks << endl
		<< "Перемещений выполнено: " << exchanges << endl;
}
void sort_by_exchange(int n, int m, char **matrix) {
	int checks = 0;
	int exchanges = 0;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int a = 1; a < m; a++) {
			for (int j = m - 1; j >= a; j--) {
				checks++;
				if (matrix[i][j - 1] > matrix[i][j]) {
					temp = matrix[i][j - 1];
					matrix[i][j - 1] = matrix[i][j];
					matrix[i][j] = temp;
					exchanges++;
				}
			}
		}
	}
	cout << endl << "Сортировка завершена." << endl
		<< "Сравнений выполнено: " << checks << endl
		<< "Перемещений выполнено: " << exchanges << endl;
}