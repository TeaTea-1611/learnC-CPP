#include <iostream>
#include <cmath>

using namespace std;

int tinhTong(int n, int x);
int luyThua(int x, int n);

int main() {
	int n, x;
	cin >> n >> x;

	cout << tinhTong(n, x);
	
	return 0;
}

int tinhTong(int n, int x){
	if (n == 0){
		return 1;
	}
	else{
		// return tinhTong(n - 1, x) + pow(x, n);
		return tinhTong(n - 1, x) + luyThua(x, n);
	}
}

int luyThua(int x, int n){
	if (n == 0){
		return 1;
	}
	else{
		return luyThua(x, n - 1) * x;
	}
}