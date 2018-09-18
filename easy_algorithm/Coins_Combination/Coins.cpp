#include <iostream>
#include <vector>

using namespace std;

int coins[] = { 0,5,10,20,50,100,200,500,1000,2000,5000,10000 };

int Count(int sum) {
	vector<vector<int>> dp(12, vector<int>(sum + 1, 0));
	for (int i = 0; i < 12; i++)
		dp[i][0] = 1;
	for (int i = 1; i < 12; i++) {
		for (int j = 5; j <= sum; j += 5) {
			for (int k = 0; k <= j / coins[i]; k++) {
				dp[i][j] += dp[i - 1][j - coins[i] * k];
			}
		}
	}
	return dp[11][sum];
}

int main() {
	cout << Count(20) << endl;
	cout << Count(200) << endl;
	return 0;
}