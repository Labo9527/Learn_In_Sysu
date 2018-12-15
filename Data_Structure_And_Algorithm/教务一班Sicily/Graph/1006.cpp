#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visited[101];
bool edge[101][101];
int path[101];

int BFS(int s) {
	memset(path, -1, sizeof(path));
	memset(visited, false, sizeof(visited));
	int max1 = -1;
	int max2 = -2;
	queue<int> book;
	book.push(s);
	visited[s] = true;
	path[s] = 0;
	while (!book.empty()) {
		int a = book.front();
		book.pop();
		if (path[a] > max1) {
			max2 = max1;
			max1 = path[a];
		}
		else if (path[a] > max2)
			max2 = path[a];
		for (int i = 0; i <= 100; i++) {
			if (edge[i][a]&&!visited[i]) {
				visited[i] = true;
				path[i] = path[a] + 1;
				book.push(i);
			}
		}
	}
	if (max1 < 0)
		max1 = 0;
	if (max2 < 0)
		max2 = 0;
	return max1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, a, b;
		memset(edge, false, sizeof(edge));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			edge[a][b] = true;
			edge[b][a] = true;
		}
		int max = -1;
		for (int i = 0; i <= 100; i++) {
			int t = BFS(i);
			if (max < t)
				max = t;
		}
		cout << max << endl;
	}
	return 0;
}