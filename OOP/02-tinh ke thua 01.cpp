#include <iostream>

using namespace std;

class A
{
public:
	A() {
		cout << "Khoi tao A" << endl;
	}
	~A() {
		cout << "Huy bo A" << endl;
	}
};

class B : public A
{
public:
	B() {
		cout << "Khoi tao B" << endl;
	}
	~B() {
		cout << "Huy bo B" << endl;
	}
};

class C : public B
{
public:
	C() {
		cout << "Khoi tao C" << endl;
	};
	~C() {
		cout << "Huy bo C" << endl;
	};
};

int main() {
	C x;
	return 0;
}