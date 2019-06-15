#include <iostream>
#include <exception>
#include <locale>
#include "module.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	SqMatr<int> A;
	SqMatr<int> B;
	cin >> A;
	cin >> B;
	cout << A;
	cout << B;

	SqMatr<int> C = A + B;
	cout << C;

	SqMatr<int> D = A * B;
	cout << D << endl;

	system("pause");
	return 0;
}