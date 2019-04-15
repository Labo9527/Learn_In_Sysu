#include <iostream>
#include <string.h>
#define MAX 1000000

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main() {
	int n, k, q;
	int a, b, c;
	int edge[110][110];
	while (cin >> n >> k >> q) {
		for (int i = 0; i < 110; i++)
			for (int j = 0; j < 110; j++)
				edge[i][j] = MAX;
		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c;
			edge[a][b] = min(edge[a][b], c);
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				edge[i][i] = 0;
				for (int j = 1; j <= n; j++) {
					edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
				}
			}
		}
		for (int i = 0; i < q; i++) {
			cin >> a >> b;
			if (edge[a][b] < MAX)
				cout << edge[a][b] << endl;
			else
				cout << -1 << endl;
		}
	}
	return 0;
}