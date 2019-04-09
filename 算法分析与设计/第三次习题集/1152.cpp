#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>


using namespace std;

int board[5][6];
int vis[5][6];
int dx[] = { -2,2,-1,1,-2,2,-1,1 };
int dy[] = { -1,1,-2,2,1,-1,2,-2 };
vector<int> res;

bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < 5 && y < 6;
}

bool dfs(int count,int n,int m) {
	if (count == 30)
		return true;
	for (int i = 0; i < 8; i++) {
		int n1 = n + dx[i];
		int m1 = m + dy[i];
		if (valid(n1, m1) && vis[n1][m1] == -1) {
			vis[n1][m1] = 0;
			if (dfs(count + 1, n1, m1)) {
				res.insert(res.begin(), board[n1][m1]);
				return true;
			}
			vis[n1][m1] = -1;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 6; j++)
			board[i][j] = 6 * i + j + 1;
	int N;
	while (cin >> N&&N != -1) {
		res.clear();
		memset(vis, -1, sizeof(vis));
		int m = (N - 1) % 6;
		int n = (N - 1) / 6;	//board[n][m]
		int count = 1;
		vis[n][m] = 0;
		dfs(count, n, m);
		res.insert(res.begin(), N);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i != res.size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}