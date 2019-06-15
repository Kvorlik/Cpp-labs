#include <locale>
#include <stdexcept>
using namespace std;

class CreateException : public runtime_error {
public:
	CreateException();
};

template <typename T>
class Array {
private:
	T* strng;
	T* ptr;
	int count;
public:
	Array(int size, const T* str);
	~Array();
	Array(const Array& other);
	void setstring(T* str);
	T* getptr();
	int getcount();
	void change();
};

template <typename T>
class MyString : public Array<T> {
public:
	MyString(int size, const T* str);
	~MyString();
	void change();
};