#include <iostream>

using namespace std;

int R, C, xC, yC, dem, kq = 9999;
char a[110][110];
bool ddau[110][110];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void Try(int x, int y);

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'C') {
				xC = i;
				yC = j;
			}
			if (a[i][j] == '*') {
				ddau[i][j] = true;
			}
		}
	}
	ddau[xC][yC] = true;
	Try(xC, yC);
	cout << kq;
	return 0;
}

void Try(int x, int y) {
	if (x == 1 && y == 1) {
		if (dem < kq) kq = dem;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 1 && xx <= R && yy >= 1 && yy <= C && ddau[xx][yy] == false) {
				dem++;
				ddau[xx][yy] = true;
				Try(xx, yy);
				dem--;
				ddau[xx][yy] = false;
			}
		}
	}
}