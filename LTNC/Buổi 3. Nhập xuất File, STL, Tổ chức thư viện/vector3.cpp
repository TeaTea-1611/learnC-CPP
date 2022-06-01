#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool ktSCP(int n);

int main() {
	vector<int> v;
	int x;
	while(cin >> x) v.push_back(x);

	// sắp xếp tăng dần vector
	sort(v.begin(), v.end());

	// Cách 1:
	// xóa SCP bằng cách duyệt từng phần tử => kiểm tra => xóa
	for (int i = 0; i < v.size(); i++){
		if (ktSCP(v[i])){
			v.erase(v.begin()+i);
		}
	}
	cout << endl;

	// Cách 2:
	// xóa SCP bằng lệnh remove_if
	vector<int>::iterator res;
	res = remove_if(v.begin(), v.end(), ktSCP);
	
	// Xuất số chẵn
	vector<int>::iterator it;
	for (it = v.begin(); it < res; it++) {
		if (*it % 2 == 0)
			cout << *it << " ";
	}
	cout << endl;
	
	
	return 0;
}

bool ktSCP(int n){
	int x = sqrt(n);
	return (x*x == n);
}