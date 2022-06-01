//QuickSort
//Phân Hoạch Lomuto

#include <iostream>
#include <fstream>

using namespace std;

int partition(int a[], int l, int r) {
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (a[j] <= pivot) {
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void quickSort(int a[], int l, int r) {
	if (l >= r) return;
	int p = partition(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r);
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
  quickSort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    ofile << a[i] << " ";
  }
  ifile.close();
  ofile.close();
	return 0;
}