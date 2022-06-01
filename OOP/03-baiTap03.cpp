#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class People
{
private:
	string hoten, quequan;
	int namsinh;
public:
	People(){};
	~People(){};
	void Nhap() {
		getline(cin, hoten);
		cin >> namsinh;
		cin.ignore();
		getline(cin, quequan);
	}
	void Xuat(){
		cout << "Ho Ten: " << hoten << endl;
		cout << "Nam Sinh: " << namsinh << endl;
		cout << "Que quan: " << quequan << endl;
	}
	string getName() {
		return hoten;
	}
	string getHT() {
		return quequan;
	}
	int getNamSinh() {
		return namsinh;
	}
	void Set(string ht, string qq, int ns) {
	    hoten = ht;
	    namsinh = ns;
	    quequan = qq;
	}
};

class SV : public People
{
private:
	string Khoa;
	int cnt;
	float diem[20];
public:
	SV(){
		cnt = 0;
	};
	~SV(){};
	void Nhap() {
		People::Nhap();
		getline(cin, Khoa);
		while (cin >> diem[cnt++]);
	}
	void Xuat() {
		People::Xuat();
		cout << "Khoa: " << Khoa << endl;
		cout << "Diem cac mon: ";
		float sum = 0;
		for (int i = 0; i < cnt - 1; ++i)
		{
			cout << diem[i] << " ";
			sum += diem[i];
		}
		cout << endl;
		cout << "Diem trung binh: ";
		cout << fixed << setprecision(2) << sum / (cnt - 1);
	}
};

int main() {
	SV a;
	a.Nhap();
	a.Xuat();
	return 0;
}