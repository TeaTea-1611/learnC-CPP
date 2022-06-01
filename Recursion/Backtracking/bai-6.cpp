// Cho một ma trận NxM ô, mỗi ô chứa thông tin như sau:

// 0: ô có thể đi đến

// #: ô không thể đi đến

// x: được cộng thêm x năng lượng.

// -x: bị giảm thêm x năng lượng.

// (với x là 1 số nguyên dương từ 1 đến 100)

// Một con robot có thể di chuyển theo hướng đi qua phải, hoặc đi xuống (mỗi lần đi một ô). Ban đầu robot có K năng lượng dùng để di chuyển, mỗi lần di chuyển sang một ô năng lượng sẽ giảm đi 1 (đơn vị). Nếu năng lượng của robot bằng 0 thì sẽ không di chuyển được.

// Yêu cầu là hãy xác định xem robot có thể di chuyển từ vị trí A có thể đến được vị trí B hay không? Nếu có xuất YES và năng lượng còn lại, ngược lại xuất NO.

// Nếu có nhiều phương án, hãy xuất phương án có năng lượng còn lại là lớn nhất.

// Input: nhập từ file robot.inp

// -         Dòng 1: Chứa 3 số N, M và K

// -         Dòng 2: chứa tọa độ A

// -         Dòng 3 chứa tọa độ B

// -         N dòng tiếp theo, mỗi dòng chứ M số (hoặc dấu #) (mỗi số là 1 trong 3 số 0, x, -x hoặc #), mỗi số cách nhau 1 khoảng cách



// Output: xuất ra file robot.out

// -         Xuất NO nếu robot không đến được B ngược lại xuất YES và năng lượng còn lại.

// Lưu ý: ma trận được đánh số dòng từ 0 đến N-1, cột từ 0 đến M-1.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int a[100][100], N, M, K, xA, yA, xB, yB, du;
bool dd[100][100];
int dx[] = {0, 1};
int dy[] = {1, 0};
string s;

ifstream in;
ofstream out;

int toNum(string s) {
	int n = 0;
	if (s[0] == '-') {
		for (int i = 1; i < s.size(); i++) {
			n = n * 10 + (int)s[i] - 48;
		}
		return -n;
	}
	for (int i = 0; i < s.size(); i++) {
			n = n * 10 + (int)s[i] - 48;
	}
	return n;
}

void Try(int x, int y) {
	if (x == xB && y == yB) {
		if (K > du) {
			du = K;
		}
	}
	else {
		for (int i = 0; i <= 1; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < N && yy < M && dd[xx][yy] == false && K > 0) {
				K--;
				K += a[xx][yy];
				Try(xx, yy);
				K -= a[xx][yy];
				K++;
			}
		}
	}
}

int main() {
	in.open("robot.inp");
	out.open("robot.out");
	in >> N >> M >> K >> xA >> yA >> xB >> yB;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			in >> s;
			if (s == "#") {
				dd[i][j] = true;
			}
			else {
				a[i][j] = toNum(s);
			}
		}
	}
	
	Try(xA, yA);
	if(du) {
		out << "YES" << endl;
		out << du;
	}
	else {
		out << "NO" << endl;
	}
	in.close();
	out.close();
	return 0;
}