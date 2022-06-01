#include <iostream>

using namespace std;

struct BacNhat{
	int a, b;
};

istream& operator >> (istream &in, BacNhat &p);
ostream& operator << (ostream &out, BacNhat p);
int tinhGiaTri(BacNhat p, int x);
BacNhat operator + (BacNhat p1, BacNhat p2);
bool operator == (BacNhat p1, BacNhat p2);

int main() {
	BacNhat f1, f2;
	int x;
	cin >> f1;
	cin >> f2;
	cin >> x;

	cout << f1 << endl;
	cout << f2 << endl;
	cout << f1 << "+" << f2 << "=" << f1 + f2 << endl;
	cout << tinhGiaTri(f1, x) << endl;
	cout << tinhGiaTri(f2, x) << endl;
	if (f1 == f2)
		cout << "TRUE";
	else
		cout << "FALSE";
	
	return 0;
}

istream& operator >> (istream &in, BacNhat &p){
	in >> p.a >> p.b;
	return in;
}
ostream& operator << (ostream &out, BacNhat p){
	out << p.a << "x+" << p.b;
	return out;
}
int tinhGiaTri(BacNhat p, int x){
	return p.a*x + p.b;
}
BacNhat operator + (BacNhat p1, BacNhat p2){
	BacNhat kq;
	kq.a = p1.a + p2.a;
	kq.b = p1.b + p2.b;
	return kq;
}
bool operator == (BacNhat p1, BacNhat p2){
	return (p1.a + p1.b == p2.a + p2.b);
}