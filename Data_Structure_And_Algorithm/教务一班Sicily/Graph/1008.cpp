#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char graph[110][110];
int m, n;

int dx[] = { 1,-1,0,0 ,1,-1,1,-1 };
int dy[] = { 0,0,1,-1 ,1,-1,-1,1 };

bool valid(int x, int y) {
	return x >= 0 && x < m&&y >= 0 && y < n;
}

int BFS() {
	int visit[101][101];
	memset(visit, false, sizeof(visit));
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && graph[i][j] == '@') {
				count++;
				queue <pair<int, int>> book;
				book.push(make_pair(i, j));
				while (!book.empty()) {
					int ax = book.front().first;
					int ay = book.front().second;
					book.pop();
					for (int i = 0; i < 8; i++) {
						int nx = ax + dx[i];
						int ny = ay + dy[i];
						if (valid(nx, ny) && graph[nx][ny] == '@' && !visit[nx][ny]) {
							visit[nx][ny] = true;
							book.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	return count;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}
		cout << BFS() << endl;
	}
	return 0;
}