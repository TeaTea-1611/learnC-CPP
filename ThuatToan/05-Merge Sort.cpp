//Merge Sort

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Trộn 2 dãy con: dãy 1 [l, m], dãy 2 [m + 1, r]
int merge(int a[], int left, int middle, int right) {
	vector<int> x(a + left, a + middle + 1);
	vector<int> y(a + middle + 1, a + right + 1);
	long long i = 0, j = 0;
	int count = 0;
	while (i < x.size() && j < y.size()) {
		if (x[i] <= y[j]) {
			a[left] = x[i];
			++left; ++i;
		}
		else {
			count += x.size() - i; 
			a[left] = y[j];
			++left; ++j;
		}
	}
	while (i < x.size()) {
		a[left] = x[i];
		++left; ++i;
	}
	while (j < y.size()) {
		a[left] = y[j];
		++left; ++j;
	}
	return count;
}

int mergeSort(int a[], int left, int right) {
	int count = 0;
	if (left < right) {
		int middle = (left + right) / 2;
		count += mergeSort(a, left, middle);
		count += mergeSort(a, middle + 1, right);
		count += merge(a, left, middle, right);
	}
	return count;
}

int main() {
	ifstream ifile;
	ofstream ofile;
	ifile.open("../input.txt");
	ofile.open("../output.txt");
	int n;
  ifile >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    ifile >> a[i];
  }
  ofile << "So cap nghich the: " << mergeSort(a, 0, n - 1) << endl;
  for (int i = 0; i < n; i++) {
    ofile << a[i] << " ";
  }
  ifile.close();
  ofile.close();
	return 0;
}