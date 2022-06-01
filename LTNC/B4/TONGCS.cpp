#include <iostream>

using namespace std;

int tongChuSo(int n);

int main() {
	int n;
	cin >> n;

	cout << tongChuSo(n);
	
	return 0;
}

int tongChuSo(int n){
	if (n < 10){
		return n;
	}
	else{
		return n % 10 + tongChuSo(n / 10);
	}
}