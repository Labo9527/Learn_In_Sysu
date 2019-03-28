#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

#define INF 100000000

using namespace std;

struct node {
	int x, y;
	node() {};
	node(int a, int b) :x(a), y(b) {};
};

bool cmp(node a, node b) {
	return a.x < b.x;
}

double dist(node a, node b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y , 2));
}

double min(double a, double b) {
	if (a < b)
		return a;
	return b;
}

int main() {
	int n;
	while (cin >> n) {
		int x, y;
		double f[110][110];
		vector<node> q;
		q.push_back(node(0, 0));
		for (int i = 1; i <= n; i++) {
			cin >> x >> y;
			q.push_back(node(x, y));
			for (int j = 0; j < n; j++)
				f[i][j] = INF;
		}
		sort(q.begin(), q.end(), cmp);
		f[2][1] = dist(q[2], q[1]);
		for (int i = 3; i <= n; i++) {
			for (int j = 0; j < i - 1; j++) {
				f[i][j] = f[i - 1][j] + dist(q[i], q[i - 1]);	//两种转移方案
			}
			for (int j = 1; j < i - 1; j++) {
				f[i][i - 1] = min(f[i][i - 1], f[i - 1][j] + dist(q[i], q[j]));
			}
		}
		printf("%.2lf\n", f[n][n - 1] + dist(q[n], q[n - 1]));
	}
	return 0;
}