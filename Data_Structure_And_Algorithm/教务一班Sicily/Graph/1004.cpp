#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <cstring>

using namespace std;

bool visit[101];
int EdgeType[101][101];
bool Edge[101][101];

int n, m, a, b;

bool AllVisited(int a) {
	for (int i = 1; i <= n; i++) {
		if (Edge[a][i] && !visit[i])
			return false;
	}
	return true;
}

void dfs(int t) {
	for (int i = 1; i <= n; i++) {
		if (Edge[t][i] == true) {
			if (!visit[i]) {
				EdgeType[t][i] = 0;
				visit[i] = true;
				dfs(i);
			}
			else {
				if (!AllVisited(i)) {
					visit[i] = true;
					EdgeType[t][i] = 1;
				}
				else {
					visit[i] = true;
					if (t == 1)
						EdgeType[t][i] = 2;
					else
						EdgeType[t][i] = 3;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(Edge, false, sizeof(Edge));
	memset(visit, false, sizeof(visit));
	memset(EdgeType, 0, sizeof(EdgeType));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		Edge[a][b] = true;
	}
	int k;
	cin >> k;
	string str[4] = { "Tree Edge","Back Edge","Down Edge","Cross Edge" };
	visit[1] = true;
	dfs(1);
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		cout << "edge (" << a << "," << b << ") is " << str[EdgeType[a][b]] << endl;
	}
	return 0;
}