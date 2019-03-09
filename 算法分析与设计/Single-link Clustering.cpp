#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
	int x;
	int y;
	node(int a, int b) :x(a), y(b) {};
	node() {};
};

int cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	while (cin >> n >> k) {
		vector<node> p1;
		vector<int> p2;
		int vis[110];
		double distance[110][110];
		double ReadyToSelect[110];
		vector<double> MST;
		for (int i = 0; i < n; i++) {
			node sample;
			vis[i] = 0;
			cin >> sample.x >> sample.y;
			p1.push_back(sample);
		}
		for (int i = 0; i < n; i++) {
			distance[i][i] = 0;
			for (int j = i + 1; j < n; j++) {
				distance[i][j] = distance[j][i] = sqrt(pow(p1[i].x - p1[j].x, 2) + pow(p1[i].y - p1[j].y, 2));
			}
		}
		for (int i = 0; i < n; i++) {
			ReadyToSelect[i] = distance[0][i];
		}
		vis[0] = 1;
		for (int i = 1; i < n; i++) {
			double MinEdge = 0x3f3f3f3f;
			int pos = 0;
			for (int j = 1; j < n; j++) {
				if (vis[j] == 0 && ReadyToSelect[j] < MinEdge) {
					pos = j;
					MinEdge = ReadyToSelect[j];
				}
			}
			vis[pos] = 1;
			MST.push_back(MinEdge);
			for (int j = 1; j < n; j++) {
				if (vis[j] == 0 && distance[pos][j] < ReadyToSelect[j])
					ReadyToSelect[j] = distance[pos][j];
			}
		}
		sort(MST.begin(), MST.end(), greater<double>());
		printf("%.2lf\n", MST[k - 2]);
	}
	return 0;
}