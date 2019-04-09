#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>


using namespace std;

struct point {
	int x, y, next;
	point() {};
	point(int a = 0, int b = 0, int c = 0) :x(a), y(b), next(c) {};
};

int board[8][8];
int vis[8][8];
int dx[] = { -2, -1, 1, 2, 2,  1,  -1, -2 };
int dy[] = { 1,  2,  2, 1, -1, -2, -2, -1 };
vector<int> res;

bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int cal(int n, int m) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		int n1 = n + dx[i];
		int m1 = m + dy[i];
		if (valid(n1, m1) && vis[n1][m1] == -1)
			count++;
	}
	return count;
}

bool cmp(point a, point b) {
	return a.next < b.next;
}

inline bool dfs(int count,int n,int m) {
	if (count == 64)
		return true;
	vector<point> r;
	for (int i = 0; i < 8 ; i++) {
		int n1 = n + dx[i];
		int m1 = m + dy[i];
		if (valid(n1, m1) && vis[n1][m1] == -1) {
			r.push_back(point(n1, m1, cal(n1, m1)));
		}
		/*
		if (valid(n1, m1) && vis[n1][m1] == -1) {
			vis[n1][m1] = 0;
			if (dfs(count + 1, n1, m1)) {
				res.insert(res.begin(), board[n1][m1]);
				return true;
			}
			vis[n1][m1] = -1;
		}
		*/
	}
	sort(r.begin(), r.end(),cmp);
	for (int i = 0; i < r.size(); i++) {
		int n1 = r[i].x;
		int m1 = r[i].y;
		vis[n1][m1] = 0;
		if (dfs(count + 1, n1, m1)) {
			res.insert(res.begin(), board[n1][m1]);
			return true;
		}
		vis[n1][m1] = -1;
	}
	return false;
}

int main() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = 8 * i + j + 1;
	int N;
	while (cin >> N&&N != -1) {
		res.clear();
		memset(vis, -1, sizeof(vis));
		int m = (N - 1) % 8;
		int n = (N - 1) / 8;	//board[n][m]
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