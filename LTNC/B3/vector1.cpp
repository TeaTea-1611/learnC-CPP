#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int x;
	while (cin >> x){
		v.push_back(x);
	}

	// xuất vector giống như mảng
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	// xuất vector sử dụng iterator - con trỏ
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	// xuất ngược vector bằng cách duyệt ngược chỉ số
	for (int i = v.size() - 1; i >= 0; i--){
		cout << v[i] << " ";
	}
	cout << endl;

	// duyệt iterator ngược từ v.end -> v.begin
	for (it = v.end() - 1; it >= v.begin(); it--){
		cout << *it << " ";
	}
	cout << endl;

	// xuất ngược vector dùng reverse_iterator
	vector<int>::reverse_iterator ri;
	for (ri = v.rbegin(); ri != v.rend(); ri++){
		cout << *ri << " ";
	}

	cout << endl;
	// v[0] = v.front() : phần tử đầu
	// v[v.size()-1] = v.back(): phần tử cuối

	return 0;
}