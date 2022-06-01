#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DoanhNghiep {
private:
	string ma, ten;
	int soLuong;
public:
	void nhap();
	void xuat();
	bool cmp(DoanhNghiep a);
};

void DoanhNghiep::nhap() {
	cin >> ma;
	cin.ignore();
	getline(cin, ten);
	cin >> soLuong;
}

void DoanhNghiep::xuat() {
	cout << ma << " " << ten << " " << soLuong << endl; 
}

bool DoanhNghiep::cmp(DoanhNghiep a) {
	return soLuong < a.soLuong;
}

int main() {
	int n;
	cin >> n;
	DoanhNghiep a[n];
	for (int i = 0; i < n; ++i) {
		a[i].nhap();
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i].cmp(a[j])) {
				DoanhNghiep tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (DoanhNghiep x : a) {
		x.xuat();
	}
	return 0;
}

// 4
// VIETTEL
// TAP DOAN VIEN THONG QUAN DOI VIETTEL
// 40
// FSOFT
// CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE
// 300
// VNPT
// TAP DOAN BUU CHINH VIEN THONG VIET NAM
// 200
// SUN
// SUN*
// 50