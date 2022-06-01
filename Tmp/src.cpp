// #include <iostream>
// #include <string>
// #include <sstream>
// #include <iomanip>
// using namespace std;

// class Diem {
// private:
// 	double a[100];
// 	int n;
// 	double& operator [] (int i) {
// 		return a[i];
// 	}
// public:
// 	Diem() {
// 		this->n = 0;
// 		for(int i = 0; i < 100; i++) {
// 			this->a[i] = 0;
// 		}
// 	}
// 	~Diem() {}
// 	double getDiem(int i) {
// 		return a[i];
// 	}
// 	friend istream& operator >> (istream &is, Diem& a) {
// 		while (is >> a[a.n]) a.n++;
// 		return is;
// 	}
// 	friend ostream& operator << (ostream &os, Diem a) {
// 		for (int i = 0; i < a.n; ++i)
// 		{
// 			os << a[i] << " ";
// 		}
// 		return os;
// 	}
// 	double diemTB() {
// 		double sum = 0;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			sum += a[i];
// 		}
// 		return sum / n;
// 	}
// };

// class SinhVien
// {
// private:
// 	string hoten, ms;
// 	Diem diem;
// public:
// 	SinhVien(string a = "", string b = ""){
// 		hoten = a;
// 		ms = b;
// 	};
// 	~SinhVien(){};
// 	friend istream& operator >> (istream &is, SinhVien& a) {
// 		getline(cin, a.hoten);
// 		getline(cin, a.ms);
// 		is >> a.diem;
// 		return is;
// 	}
// 	friend ostream& operator << (ostream &os, SinhVien a) {
// 		os << "Ho Ten: " << a.hoten << endl;
// 		os << "Ma Sinh Vien: " << a.ms << endl;
// 		os << "DTB: " << fixed << setprecision(1) << a.diem.diemTB();
// 		return os; 
// 	}
// 	bool operator < (SinhVien a) {
// 		return this->diem.diemTB() < a.diem.diemTB();
// 	}
// };

// int main() {
// 	SinhVien a, b;
// 	cin >> a;
// 	cout << a;
// 	return 0;
// }
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Chuoi
{
private:
	string s;
public:
	Chuoi(string ss = ""){
		s = ss;
	};
	Chuoi(const Chuoi &a) {
		s = a.s;
	}
	~Chuoi(){};
	friend istream& operator >> (istream &is, Chuoi &a) {
		getline(cin, a.s);
		return is;
	}
	friend ostream& operator << (ostream &os, Chuoi a) {
		os << a.s;
		return os;
	}
	int getStringLength() {
		return this->s.size();
	}
	void stringUpperCase() {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	}
	bool operator > (Chuoi a) {
		return s.size() > a.s.size();
	}
	
};

int main() {
	string str;
	getline(cin, str);
	for(int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	return 0;
}