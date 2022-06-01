#include <iostream>

using namespace std;

int N, X[100];

void in() {
	for (int i = 0; i < N; ++i)
	{
		cout << X[i];
	}
	cout << endl;
}

void Try(int i) {
	if (i == N) {
		in();
	}
	else {
		for (int j = 0; j <= 1; ++j) {
			X[i] = j;
			Try(i + 1);
		}
	}
}

int main() {
	cin >> N;
	Try(0);
	return 0;
}