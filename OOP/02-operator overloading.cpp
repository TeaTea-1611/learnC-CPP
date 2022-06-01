#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name, id, bd;
	double gba;
	static int count;
public:
	friend istream& operator >> (istream &is, Student &a);
	friend ostream& operator << (ostream &os, Student a);
};

int main() {
	Student a;
	cin >> a;
	cout << a;
	return 0;
}

istream& operator >> (istream &is, Student &a) {
	cout << "id: ";
	is >> a.id;
	cout << "name: ";
	is.ignore();
	getline(cin, a.name);
	cout << "birthday: ";
	is >> a.bd;
	cout << "gba: ";
	is >> a.gba;
	return is;
}

ostream& operator << (ostream &os, Student a) {
	cout << "-------------------------------------------" << endl;
	os << a.id << " " << a.name << " " << a.gba << " " << a.bd << endl;
	return os;
}