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

	ofstream ofile;
	ofile.open("output.txt");
	// cout << a + b;
	ofile << a + b;
	ofile.close();
	
	return 0;
}