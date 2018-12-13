#include <iostream>
#include <queue>

using namespace std;

int graph[1010][1010];
int vis[1010];
int n, m;
int a, b;

int BFS() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)
			continue;
		count++;
		queue<int> book;
		book.push(i);
		while (!book.empty()) {
			int k = book.front();
			book.pop();
			vis[k] = 1;
			for (int j = 1; j <= n; j++) {
				if ((graph[k][j] || graph[j][k])&&vis[j]!=1)
					book.push(j);
			}
		}
	}
	return count;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cout << BFS() << endl;
	return 0;
}