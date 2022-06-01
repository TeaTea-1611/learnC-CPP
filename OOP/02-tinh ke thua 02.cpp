#include <iostream>

using namespace std;

class Animal
{
private:
	int age;
	float weight;
	int s;
public:
	Animal(){
		age = 0;
		weight = 0;
		s = 0;
	};
	void Set(int a, float w, int s) {
		age = a;
		weight = w;
		this->s = s;
	}
	void An() {
		cout << "Con thu dang an" << endl;
	}
	void Print() {
		cout << "tuoi: " << age << endl;
		cout << "can nang: " << weight << endl;
		cout << "gioi tinh: ";
		if (s) {
			cout << "nam" << endl;
		}
		else {
			cout << "nu" << endl;
		}
	}
	~Animal(){};
};

class Elephant : public Animal
{
private:
	int root;
public:
	Elephant() {
		root = 0;
	};
	void Set(int a, float w, int s, int r) {
		Animal::Set(a, w, s);
		root = r;
	}
	void Print() {
		Animal::Print();
		cout << "xuat xu: ";
		if (root) {
			cout << "Chau A" << endl;
		}
		else {
			cout << "Chau Phi" << endl;
		}
	}
	~Elephant(){};
};

int main() {
	Elephant a;
	a.Set(18, 60, 0, 1);
	a.Print();
	return 0;
}