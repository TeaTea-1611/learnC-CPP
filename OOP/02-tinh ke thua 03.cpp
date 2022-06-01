#include <iostream>

using namespace std;

class Array
{
private:
	int Sopt;
	int Data[100];
public:
	Array(){
		Sopt = -1;
	};
	~Array(){};

	void Input() {
		Sopt++;
		while (cin >> Data[Sopt]) Sopt++;
	}
	void Output() {
		for (int i = 0; i < Sopt; i++) {
			cout << Data[i] << " ";
		}
		cout << endl;
	}
	int getSopt() {
		return Sopt;
	}
	int getData() {
		return Data[Sopt];
	}
};

class Stack : public Array
{
public:
	Stack(){};
	int isEmpty() {
		return Array::getSopt();
	}
	~Stack(){};
};

int main() {
	Stack a;
	a.Input();
	a.Pop();
	a.Push(10);
	a.Output();
	return 0;
}