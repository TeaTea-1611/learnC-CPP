#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, cnt;
int a[100][100];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void Try(int i, int j);

int main() {
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cnt++;
	a[x][y] = 1;
	Try(x, y);
	cout << cnt;
	return 0;
}

void Try(int i, int j) {
	for (int k = 0; k < 4; k++) {
		int xx = i + dx[k];
		int yy = j + dy[k];
		if (xx >= 1 && yy >= 1 && xx <= n && yy <= m && a[xx][yy] == 0) {
			a[xx][yy] = 1;
			cnt++;
			Try(xx, yy);
		}
	}
	
}

// input
// 4 5 2 4
// 0 0 1 0 0
// 0 1 0 0 1
// 1 0 0 0 0
// 0 1 0 0 1
// 
// output
// 10