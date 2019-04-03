#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

double max(double a, double b) {	//���и��Ż����㷨������㷨�ĸ��Ӷ���M*��N*6
	if (a > b)
		return a;
	return b;
}

int main() {	//�൱��ת����01��������
	int M;
	double dp[8][10010];	//����ͬ�໹����һ����������
	int a[8];
	double value[] = {0,0.01,0.05,0.1,0.25,0.5,1 };
	int weight[] = { 0,3,5,2,6,11,8 };
	while (cin >> M) {
		for (int i = 1; i <= 6; i++)
			cin >> a[i];
		for (int i = 0; i <= M; i++)
			dp[0][i] = 0;
		for (int i = 0; i <= 6; i++)
			dp[i][0] = 0;
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= M; j++) {
				dp[i][j] = 0;
				for (int k = 0; k <= a[i]; k++) {	//�൱��ͬ���еķ�����Ʒ
					if (weight[i] * k > j)
						break;
					dp[i][j] = max(dp[i][j], k*value[i] + dp[i - 1][j - weight[i] * k]);
				}
			}
		}
		printf("$%.2f\n", dp[6][M]);
	}
	return 0;
}