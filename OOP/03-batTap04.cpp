#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Diem
{
private:
	float diem[100];
	int cnt;
	float& operator [] (int i) {
		return diem[i];
	}
public:
	Diem(){
		cnt = 0;
		for (int i = 0; i < 100; ++i)
		{
			diem[i] = 0;
		}
	};
	~Diem(){};
	friend istream& operator >> (istream &is, Diem& a) {
		while (is >> a[a.cnt]) a.cnt++;
		return is;
	}
	friend ostream& operator << (ostream &os, Diem a) {
		for (int i = 0; i < a.cnt; ++i)
		{
			os << a[i] << " ";
		}
		return os;
	}
	float DTB() {
		float sum = 0;
		for (int i = 0; i < cnt; ++i)
		{
			sum += diem[i];
		}
		return cnt > 0 ? sum / cnt : 0;
	}
	float get(int i) {
		return diem[i - 1];
	}
};

class SinhVien
{
private:
	string hoten, ms;
	Diem d;
public:
	SinhVien(){
		hoten = "";
		ms = "";
	};
	~SinhVien(){};
	friend istream& operator >> (istream &is, SinhVien& a) {
		getline(is, a.hoten);
		getline(is, a.ms);
		is >> a.d;
		return is;
	}
	friend ostream& operator << (ostream &os, SinhVien a) {
		os << "Ho Ten: " << a.hoten << endl;
		os << "Ma Sinh Vien: " << a.ms << endl;
		os << "DTB: " << fixed << setprecision(1) << a.d.DTB();
		return os;
	}
	bool operator < (SinhVien a) {
		return d.DTB() < a.d.DTB();
	}
};

int main() {
	Diem a;
	cin >> a;
	cout << a.get(1);
	// SinhVien a, b;
	// cin >> a;
	// cout << a << endl;
	// cin >> b;
	// cout << b << endl;
	// if (a < b) {
	// 	cout << "false";
	// }
	// else {
	// 	cout << "true";
	// }
	return 0;
}