#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		int s1[510];
		int s2[510];
		int dp[510][510];
		memset(dp, 0, sizeof(dp));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)	//cong 0 kaishi ze houmian m ge yao suo yin s1[m-1]
			cin >> s1[i];
		for (int i = 1; i <= m; i++)
			cin >> s2[i];
		sort(s1 + 1, s1 + n + 1);
		sort(s2 + 1, s2 + m + 1);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {	//[0~m] ge
				if (j < i) {
					dp[i][j] = 0x3f3f3f3f;
					continue;
				}
				else if (i == j&&i == 0) {
					continue;
				}
				else {
					dp[i][j] = 0x3f3f3f3f;
					if (i > 0)
						dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(s2[j] - s1[i]));
					if (j > 0)
						dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}