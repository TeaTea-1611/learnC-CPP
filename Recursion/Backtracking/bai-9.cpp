#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, x, y, cnt;
string s;
char a[100][100];
bool ddau[100][100], flag;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void Try(int i, int j);

int main() {
	cin >> n >> m >> x >> y;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cnt++;
	Try(x + 1, y + 1);
	if (flag) {
		cout << "YES" << endl;
		cout << "(" << x << "," << y << ")";
	}
	else {
		cout << "NO";
	}
	return 0;
}

void Try(int i, int j) {
	if (cnt == s.size()) {
		flag = true;
		x = i - 1;
		y = j - 1;
	}
	else {
		for (int k = 0; k < 4; k++) {
			int xx = i + dx[k];
			int yy = j + dy[k];
			if (xx >= 1 && yy >= 1 && xx <= n && yy <= m && s[cnt] == a[xx][yy]) {
				cnt++;
				Try(xx, yy);
			}
		}
	}
}
