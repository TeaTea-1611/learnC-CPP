//Counting Sort

#include <iostream>

using namespace std;

int cnt[1000001];

int main() {
	int n;
  cin >> n;
  int a[n];
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    m = max(m, a[i]);
  }
  for (int i = 0; i <= m; i++) {
    if (cnt[i] != 0) {
    	for (int j = 0; j < cnt[i]; ++j) {
    		cout << i << " ";
    	}
    }
  }
	return 0;
}