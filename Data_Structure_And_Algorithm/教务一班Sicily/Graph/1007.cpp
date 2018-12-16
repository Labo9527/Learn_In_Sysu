#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INT = 2147483647 / 2;

int n;
int graph[505][505];
int set[505];

struct edge{
	int u;
	int v;
	int w;
};

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int MST_PRIM() {
	int latest[505];
	int max = 0;
	for (int i = 0; i < n; i++)
		latest[i] = graph[0][i];
	for (int i = 1; i < n; i++) {
		int min = 9999999;
		int k = 0;
		for (int j = 1; j < n; j++) {
			if (latest[j] != 0 && latest[j] < min) {
				k = j;
				min = latest[j];
			}
		}
		if (min > max)
			max = min;
		for (int j = 1; j < n; j++) {
			if (latest[j] > graph[k][j])
				latest[j] = graph[k][j];
		}
	}
	return max;
}

int getFather(int t) {
	return set[t] == t ? t : set[t] = getFather(set[t]);
}

int MST_KRUSKAL() {
	int max = 0;
	int vnum = 0;
	edge E[130000];
	for (int i = 0; i < n; i++)
		set[i] = i;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (graph[i][j] != 0&&graph[i][j]!=MAX_INT) {
				E[vnum].u = i;
				E[vnum].v = j;
				E[vnum++].w = graph[i][j];
			}
		}
	}
	sort(E, E + vnum, cmp);
	for (int i = 0; i < vnum; i++) {
		int set1 = getFather(E[i].u);
		int set2 = getFather(E[i].v);
		if (set1 != set2) {
			if (E[i].w > max) max = E[i].w;
				set[set1] = set2;
		}
	}
	return max;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}
		//cout << MST_PRIM() << endl;
		cout << MST_KRUSKAL() << endl;
		if (T)
			cout << endl;
	}
	return 0;
}