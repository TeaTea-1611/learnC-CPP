#include <iostream>

using namespace std;

int n;
int a[100];

void nhiPhan(int i); // thử giá trị cho vị trí i của dãy nhị phân

int main() {
	cin >> n;

	nhiPhan(0);

	return 0;
}

void nhiPhan(int i){
	if (i == n){
		// xuất dãy nhị phân - mảng a
		for (int k = 0; k < n; k++){
			cout << a[k];
		}
		cout << endl;
	}
	else{
		for (int k = 0; k <= 1; k++){
			a[i] = k;
			nhiPhan(i + 1);
		}
	}
}