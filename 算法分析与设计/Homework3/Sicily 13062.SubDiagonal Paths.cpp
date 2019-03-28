#include <iostream>

using namespace std;

int main() {
	int n;
	long long int dp[40][40];
	for (int i = 0; i <= 40; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= 40; i++) {
		for (int j = 0; j <= 40; j++) {
			if (i > j)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	while (cin >> n && n) {
		cout << dp[n][n] << endl;
	}
	return 0;
}