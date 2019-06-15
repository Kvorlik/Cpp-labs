#include <iostream>
#include <exception>
#include <locale>
using namespace std;

template <typename T> class SqMatr {
private:
	int n = 3;
	T** matr;
public:
	SqMatr() {
		try {
			matr = new T*[n];
			for (int i = 0; i < n; i++) {
				matr[i] = new T[n];
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	SqMatr(const SqMatr<T>& other) {
		try {
			matr = new T*[n];
			for (int i = 0; i < n; i++) {
				matr[i] = new T[n];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matr[i][j] = other.matr[i][j];
				}
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	~SqMatr() {
		for (int i = 0; i < n; i++) {
			delete[] matr[i];
		}
		delete[] matr;
	}

	SqMatr<T> operator + (SqMatr<T>& other) {
		try {
			SqMatr<T> result;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					result.matr[i][j] = matr[i][j] + other.matr[i][j];
				}
			}
			return result;
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	SqMatr<T> operator * (SqMatr<T>& other) { //c11 = a11 · b11 + a12 · b21 + a13 · b31
		try {
			SqMatr<T> result;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					result.matr[i][j] = 0;
					for (int k = 0; k < n; k++) {
						result.matr[i][j] += matr[i][k] * other.matr[k][j];
					}
				}
			}
			return result;
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	template <typename T> friend ostream& operator << (ostream& os, const SqMatr<T>& obj); //Способ с friend с MSDN'a
	template <typename T> friend istream& operator >> (istream& is, SqMatr<T>& obj);
};

template <typename T>
ostream& operator << (ostream& os, const SqMatr<T>& obj) {
	try {
		os << "Матрица " << &obj << endl;
		return os;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return os;
	}
}

template <typename T>
istream& operator >> (istream& is, SqMatr<T>& obj) {
	try {
		is >> obj.matr[0][i];
		return is;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return is;
	}
}