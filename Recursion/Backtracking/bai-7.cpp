#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
int a[100][100];
bool ddau[100][100];
int dx[] = {0, 1};
int dy[] = {1, 0};
vector<int> ddi;

void Try(int i, int j);

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				ddau[i][j] = true;
			}
		}
	}
	ddau[0][0] = true;
	Try(0, 0);
	if (cnt) cout << cnt;
	else cout << -1;
	return 0;
}

void Try(int i, int j) {
	if (i == n - 1 && j == m - 1) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int k = 0; k < ddi.size(); k++) {
			if (ddi[k] == 1) cnt1++;
			if (ddi[k] == 2) cnt2++;
			if (ddi[k] == 3) cnt3++;
		}
		if (cnt1 && cnt2 || 
				cnt1 && cnt3 ||
				cnt2 && cnt3) {
			cnt++;
		}
	}
	else {
		for (int k = 0; k <= 1; k++) {
			int x = i + dx[k];
			int y = j + dy[k];
			if (x < n && y < m && !ddau[x][y]) {
				ddau[x][y] = true;
				ddi.push_back(a[x][y]);
				Try(x, y);
				ddi.pop_back();
				ddau[x][y] = false;
			}
		}
	}
}