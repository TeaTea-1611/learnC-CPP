#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

class PhanSo {
private:
  ll tu, mau;
public:
  PhanSo() {
    tu = 0;
    mau = 1;
  };
  PhanSo(ll tu, ll mau);
  friend istream& operator >> (istream &is, PhanSo& a);
  friend ostream& operator << (ostream &os, PhanSo a);
  void rutGon();
};

int main() {
  PhanSo a;
  cin >> a;
  cout << a << endl;
	return 0;
}

PhanSo::PhanSo(ll tu, ll mau) {
  this->tu = tu;
  this->mau = mau;
}

istream& operator >> (istream &is, PhanSo& a) {
  is >> a.tu >> a.mau;
  return is;
}

ostream& operator << (ostream &os, PhanSo a) {
  a.rutGon();
  os << a.tu << "/" << a.mau;
  return os;
}

void PhanSo::rutGon() {
  ll g = __gcd(tu, mau);
  tu /= g;
  mau /= g;
}