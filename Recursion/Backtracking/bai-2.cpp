#include <iostream>

using namespace std;

int a[100], n, k;
bool b[100];

void xuatKetQua();
void Try(int i);

int main(){
	cin >> k >> n;
	// for (int i = 1; i < n; i++) {
	// 	b[i] = false;
	// }
	Try(0);
	return 0;
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!b[j]) {
			a[i] = j;
			if (i == k - 1)
				xuatKetQua();
			else{
				b[j] = true;
				Try(i + 1);
		  		b[j] = false;
			}
		}
	}
}

void xuatKetQua(){
	for (int i = 0; i < k; i++){
		cout << a[i];
	}
	cout << endl;
}