#include <iostream>
#include <string>

using namespace std;

class Teacher;

class Student {
private:
	string name, id, bd;
	double gba;
	static int count;
public:
	Student();//constructor
	Student(string name, string id, string bd, double gba);//constructor
	~Student();//destructor
	void nhap();
	void xuat();
	double getGba();
	void setGba(double);
	friend class Teacher;
};

class Teacher {
private:
	string name;
public:
	void update(Student&);
};

void Teacher::update(Student& a) {
	a.gba = 3.0;
};


int Student::count = 0;

Student::Student() {}

Student::Student(string name, string id, string bd, double gba) {
	this->id = id;
	this->name = name;
	this->bd = bd;
	this->gba = gba;
}

Student::~Student() {}

void Student::nhap() {
	++count;
	this->id = string(3-to_string(count).length(), '0') + to_string(count); 
	cout << "Name: ";
	getline(cin, name);
	cout << "birthday: ";
	cin.ignore();
	getline(cin, bd);
	cout << "Gba: "; cin >> gba;
}

void Student::xuat() {
	cout << "\n---------------------------------" << endl;
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "birthday: " << bd << endl;
	cout << "Gba: " << gba << endl;
}

double Student::getGba() {
	return this->gba;
}

void Student::setGba(double gba) {
	this->gba = gba;
}

int main() {
	Student a;
	a.nhap();
	Teacher t;
	t.update(a);
	a.xuat();
	return 0;
}