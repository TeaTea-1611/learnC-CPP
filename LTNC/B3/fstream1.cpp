#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int a, b;
	ifstream ifile;
	ifile.open("input.txt");

	// cin >> a >> b;
	ifile >> a >> b;
	ifile.close();

	cout << a + b;
	
	return 0;
}