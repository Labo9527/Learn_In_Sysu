#include <iostream>
#include <string.h>

using namespace std;

int n, m;
int pa[510][510];
int used[510];
int root[510];

bool adjust(int a, int b) {
	for (int i = 0; i < m; i++) {
		if (pa[a][i] == 1 && used[i] == 0) {
			root[i] = a;
			used[i] = 1;
			return true;
		}
		else if (pa[a][i] == 1 && used[i] == 1 && i != b) {
			if (adjust(root[i], i)) {
				root[i] = a;
				used[i] = 1;
				return true;
			}
		}
	}
	return false;
}

bool Find(int i) {
	for (int j = 0; j < m; j++) {
		if (used[j] == 0 && pa[i][j]) {
			used[j] = 1;
			if (root[j] == -1 || Find(root[j])) {
				root[j] = i;
				return true;
			}
		}
	}
	return false;
}

int main() {
	while (cin >> n >> m) {
		int Counter = 0;
		memset(root, -1, sizeof(root));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> pa[i][j];
		for (int i = 0; i < n; i++) {
			memset(used, 0, sizeof(used));
			if (Find(i))
				Counter++;
		}
		cout << Counter << endl;
	}
	return 0;
}