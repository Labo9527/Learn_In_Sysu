#include <iostream>

using namespace std;

int main() {
	int N;
	int W;
	cin >> N;
	int dp[1010][20];
	//参考了CSDN https://www.cnblogs.com/chenximcm/p/6285143.html 中状态转移的想法
	dp[1][0] = 1;	//空
	dp[1][1] = dp[1][2] = 1;	//上下
	dp[1][3] = 0;	//端
	dp[1][4] = 1;	//中
	dp[1][5] = 1;	//满
	for (int i = 2; i <= 1000; i++) {	//横向不能有连续两个灰色格子
		dp[i][0] = dp[i - 1][5];
		dp[i][1] = dp[i - 1][2] + dp[i - 1][5];
		dp[i][2] = dp[i - 1][1] + dp[i - 1][5];
		dp[i][3] = dp[i - 1][4];
		dp[i][4] = dp[i - 1][5] + dp[i - 1][3];
		dp[i][5] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][5] + dp[i - 1][4];
	}
	for (int i = 1; i <= N; i++) {
		cin >> W;
		cout << i << " " << dp[W][5] << endl;
	}
	return 0;
}