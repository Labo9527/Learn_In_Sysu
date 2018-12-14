#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m, a, b;
bool edge[1010][1010];
int path[1010];

int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

bool inside(int x, int y) {
	return x >= 1 && x <= n&&y >= 1 && y <= n;
}

int Compute(int t){
	bool visit[1010];
	memset(visit, false, sizeof(visit));
	queue<int> book;
	book.push(1);
	visit[1] = true;
	while (!book.empty()) {
		int a = book.front();
		book.pop();
		for (int i = 1; i <= n; i++) {
			if (edge[a][i] && !visit[i]) {
				book.push(i);
				visit[i] = true;
				path[i] = path[a]+1;
			}
		}
	}
	return -1;
}

int main() {
	memset(edge, false, sizeof(edge));
	memset(path, -1, sizeof(path));
	cin >> n >> m;
	path[1] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a][b] = true;
		edge[b][a] = true;
	}
	Compute(1);
	for (int i = 1; i <= n; i++) {
			cout << path[i];
		//if (i != n)
			cout << " ";
	}
	cout << endl;
	return 0;
}