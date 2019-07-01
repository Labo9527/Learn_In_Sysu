#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define INF 0x3f3f3f3f

int main() {
	int n, m;
	int a, b, c;
	while (cin >> n >> m, n || m) {
		int edge[110][110];
		int dis[110];
		int vis[110];
		memset(vis, 0, sizeof(vis));
		memset(dis, INF, sizeof(dis));
		memset(edge, INF, sizeof(edge));
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			edge[a][b] = edge[b][a] = c;
			if (a == 1)
				dis[b] = c;
			else if (b == 1)
				dis[a] = c;
		}
		dis[1] = 0;
		vis[1] = 1;
		for (int i = 0; i < n - 1; i++) {
			int pos = -1;
			int min = INF;
			for (int j = 1; j <= n; j++) {
				if (!vis[j] && dis[j] < min) {
					min = dis[j];
					pos = j;
				}
			}
			vis[pos] = 1;
			for (int j = 1; j <= n; j++) {
				if (!vis[j] && dis[pos] + edge[pos][j] < dis[j])
					dis[j] = dis[pos] + edge[pos][j];
			}
		}
		cout << dis[n] << endl;
	}
	return 0;
}