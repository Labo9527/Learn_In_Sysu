#include <iostream>
#include <cstring>

using namespace std;

#define MAX 0x3f3f3f3f

int main() {
	int n, m;
	while (cin >> n >> m) {
		int edge[210][210];
		int dis[210];
		memset(dis, MAX, sizeof(dis));
		memset(edge, MAX, sizeof(edge));
		for (int i = 0; i < n; i++)
			edge[n][n] = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if(edge[a][b]>c)
				edge[a][b] = edge[b][a] = c;
		}
		int s, t;
		cin >> s >> t;
		dis[s] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (dis[j] > dis[k] + edge[j][k])
						dis[j] = dis[k] + edge[j][k];
				}
			}
		}
		if (dis[t] == MAX)
			cout << "-1" << endl;
		else
			cout << dis[t] << endl;
	}
	return 0;
}