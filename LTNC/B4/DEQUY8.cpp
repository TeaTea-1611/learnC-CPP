#include <iostream>

using namespace std;

int toHop(int n, int k);

int main() {
	int n, k;
	cin >> n >> k;
	cout << toHop(n, k);
	
	return 0;
}

int toHop(int n, int k){
	if (k == n || k == 0){
		return 1;
	}
	else{
		return toHop(n - 1, k) + toHop(n - 1, k - 1);
	}
}