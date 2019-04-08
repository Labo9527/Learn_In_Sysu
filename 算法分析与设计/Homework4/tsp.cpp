#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double min(double a, double b) {
	if (a < b)
		return a;
	return b;
}

double dp[25][1100000];	//dp[i][j]表示以i为终点，经过集合j中所有点的最短距离

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		int x[25];
		int y[25];
		double dis[25][25];
		cin >> N;
		int count = pow(2, N - 1);		//用二进制串来记录集合，表示是否包含某个点
		for (int i = 0; i < N; i++) {	//输入X Y坐标
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < count; i++)
			for (int j = 0; j < N; j++)
				dp[j][i] = 10e7;	//初始化
		for (int i = 0; i < N; i++) {	//记录各点距离
			for (int j = 0; j < N; j++)
				dis[i][j] = dis[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			dp[i][0] = dis[i][0];
		}
		for (int i = 1; i < count; i++) {
			for (int j = 1; j < N; j++) {
				for (int k = 1; k < N; k++) {
					if ((1 << (k - 1)) & i) {		//判断k是否在集合i中
						dp[j][i] = min(dp[j][i], dis[j][k] + dp[k][i - (1 << (k - 1))]);		//状态转移
					}
				}
			}
		}
		double a = 10e7;	//初始化答案
		for (int i = 1; i < N; i++)
			a = min(a, dp[i][count - 1] + dis[i][N - 1]);	//因为终点必须为N，所以要选取最小的dp[i][count-1]+dis[i][N-1]
		printf("%.2lf\n", a);
	}
	return 0;
}