#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool ktSNT(int n);

int main() {
	int n, x;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++){
		// kiểm tra v[i] có phải SNT không?
		if (ktSNT(v[i])){	// v[i] là SNT
			int sum = 0;
			while(v[i] > 0){
				int r = v[i] % 10;	// r là chữ số hàng đơn vị của v[i]
				if (!ktSNT(r)){		// r không phải SNT
					sum += r;
				}
				v[i] /= 10;
			}

			cout << sum << endl;
		}
		else{	// v[i] không là SNT
			cout << -1 << endl;
		}
	}
	
	return 0;
}

bool ktSNT(int n){
	if (n < 2){
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}