#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int a, b;
	ifstream ifile;
	ofstream ofile;
	ifile.open("../../input.txt");
	ofile.open("../../output.txt");
	ifile >> a >> b;
	ofile << a + b;
	ifile.close();
	ofile.close();
	return 0;
}