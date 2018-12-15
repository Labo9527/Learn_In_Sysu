#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

bool isvalid(int a, int b) {
	return a >= 1 && a <= 8 && b >= 1 && b <= 8;
}

int dx[] = { 1,-1,1,-1,2,-2,2,-2 };
int dy[] = { 2,-2,-2,2,1,-1,-1,1 };

int BFS(string a, string b) {
	int max = -1;
	int path[10][10];
	bool visit[10][10];
	memset(visit, false, sizeof(visit));
	memset(path, -1, sizeof(path));
	int x1 = a[0] - 'a' + 1;
	int y1 = a[1] - '0';
	int x2 = b[0] - 'a' + 1;
	int y2 = b[1] - '0';
	path[x1][y1] = 0;
	queue<pair<int,int>> book;
	book.push(make_pair(x1, y1));
	while (!book.empty()) {
		int x = book.front().first;
		int y = book.front().second;
		book.pop();
		if (x == x2&&y == y2)
			return path[x][y];
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isvalid(nx, ny) && !visit[nx][ny]) {
				path[nx][ny] = path[x][y] + 1;
				visit[nx][ny] = true;
				book.push(make_pair(nx, ny));
			}
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		cout << "To get from "<<a<<" to "<<b<<" takes "<<BFS(a,b)<<" knight moves." << endl;
	}
	return 0;
}