#include <iostream>

using namespace std;

struct PhanSo {
	int tu, mau;
};

istream& operator >> (istream &in, PhanSo &p);
ostream& operator << (ostream &out, PhanSo p);
bool operator == (PhanSo p1, PhanSo p2);

template <typename T>
void xuLy();


int main() {
	char x;
	cin >> x;
	if (x == 'a'){
		xuLy<int>();
	}
	else if (x == 'b'){
		xuLy<float>();
	}
	else if (x == 'c'){
		xuLy<PhanSo>();
	}
	
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
bool operator == (PhanSo p1, PhanSo p2){
	return (p1.tu*p2.mau == p2.tu*p1.mau);
}

template <typename T>
void xuLy(){
	T a, b;
	cin >> a >> b;
	if (a == b)
		cout << "true";
	else
		cout << "false";
}