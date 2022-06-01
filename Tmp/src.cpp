#include <bits/stdc++.h>

using namespace std;

struct Arr {
	int n;
	int a[100];
	int& operator [] (int i) {
		return a[i];
	}
	void operator = (Arr m) {
		n = m.n;
		for(int i = 0; i < n; i++) {
			a[i] = m[i];
		}
	}
};

istream& operator >> (istream &is, Arr &a) {
	is >> a.n;
	for(int i = 0; i < a.n; i++) {
		is >> a.a[i];
	}
	return is;
}

ostream& operator << (ostream &os, Arr a) {
	for(int i = 0; i < a.n; i++) {
		os << a.a[i] << " ";
	}
	return os;
}

int main(){
	Arr a, b;
	cin >> a;
	b = a;
	cout << b;
	return 0;
}
