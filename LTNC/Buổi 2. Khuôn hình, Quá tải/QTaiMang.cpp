#include <iostream>

using namespace std;

struct Mang{
	int sl;	// số lượng phần tử của Mang
	int ptu[100];	// lưu các phần tử của Mang

	int& operator [] (int i){
		return ptu[i];
	}

	void operator = (Mang m){
		sl = m.sl;
		for (int i = 0; i < sl; i++){
			// ptu[i] = m.ptu[i];
			ptu[i] = m[i];
		}
	}
};

istream& operator >> (istream &in, Mang &m);
ostream& operator << (ostream &out, Mang m);
Mang operator + (Mang a, Mang b);
bool operator == (Mang a, Mang b);
bool operator != (Mang a, Mang b);

int main() {
	Mang a, b;

	cin >> a;
	cin >> b;

	//cout << a << endl;
	//cout << b << endl;
	
	if (a == b)
		cout << "yes";
	else
		cout << "no";
	return 0;
}

istream& operator >> (istream &in, Mang &m){
	in >> m.sl;
	for (int i = 0; i < m.sl; i++){
		// in >> m.ptu[i];
		in >> m[i];
	}
	return in;
}
ostream& operator << (ostream &out, Mang m){
	for (int i = 0; i < m.sl; i++){
		// out << m.ptu[i] << " ";
		out << m[i] << " ";
	}
	return out;
}
Mang operator + (Mang a, Mang b){
	Mang kq;
	if (a.sl >= b.sl){	// a dài hơn b
		kq = a;
		for (int i = 0; i < b.sl; i++){
			//kq.ptu[i] += b.ptu[i];
			kq[i] += b[i];
		}
	}
	else{				// b dài hơn a
		kq = b;
		for (int i = 0; i < a.sl; i++){
			// kq.ptu[i] += a.ptu[i];
			kq[i] += a[i];
		}
	}

	return kq;
}
bool operator == (Mang a, Mang b){
	if (a.sl != b.sl)
		return false;
	for (int i = 0; i < a.sl; i++){
		// if (a.ptu[i] != b.ptu[i]){
		if (a[i] != b[i]){
			return false;
		}
	}
	return true;
}
bool operator != (Mang a, Mang b){
	return !(a == b);
}