#include <iostream>
#include <algorithm>

using namespace std;

struct PhanSo{
	int tu, mau;
	void operator = (PhanSo a){
		tu = a.tu;
		mau = a.mau;
	}
	void operator = (int x){
		tu = x;
		mau = 1;
	}
};

istream& operator >> (istream &in, PhanSo &p);
ostream& operator << (ostream &out, PhanSo p);
PhanSo operator + (PhanSo p1, PhanSo p2);
bool operator == (PhanSo p1, PhanSo p2);
bool operator != (PhanSo p1, PhanSo p2);
PhanSo rutGon (PhanSo p);

int main() {
	PhanSo p1, p2;
	cin >> p1;
	cin >> p2;


	PhanSo p3;
	p3 = 2;
	cout << p3 << endl;

	cout << p1 + p2;
	return 0;
}

istream& operator >> (istream &in, PhanSo &p){
	in >> p.tu >> p.mau;
	return in;
}
ostream& operator << (ostream &out, PhanSo p){
	out << p.tu << "/" << p.mau;
	return out;
}
PhanSo operator + (PhanSo p1, PhanSo p2){
	PhanSo kq;
	kq.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	kq.mau = p1.mau * p2.mau;
	return rutGon(kq);
}
bool operator == (PhanSo p1, PhanSo p2){
	// if (p1.tu*p2.mau == p2.tu*p1.mau)
	// 	return true;
	// else
	// 	return false;
	return (p1.tu*p2.mau == p2.tu*p1.mau);
}
bool operator != (PhanSo p1, PhanSo p2){
	//return (p1.tu*p2.mau != p2.tu*p1.mau);
	return !(p1 == p2);
}
PhanSo rutGon (PhanSo p){
	int x = __gcd(p.tu, p.mau);
	p.tu /= x;
	p.mau /= x;
	return p;
}