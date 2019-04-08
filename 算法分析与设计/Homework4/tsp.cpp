#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double min(double a, double b) {
	if (a < b)
		return a;
	return b;
}

double dp[25][1100000];	//dp[i][j]��ʾ��iΪ�յ㣬��������j�����е����̾���

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		int x[25];
		int y[25];
		double dis[25][25];
		cin >> N;
		int count = pow(2, N - 1);		//�ö����ƴ�����¼���ϣ���ʾ�Ƿ����ĳ����
		for (int i = 0; i < N; i++) {	//����X Y����
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < count; i++)
			for (int j = 0; j < N; j++)
				dp[j][i] = 10e7;	//��ʼ��
		for (int i = 0; i < N; i++) {	//��¼�������
			for (int j = 0; j < N; j++)
				dis[i][j] = dis[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			dp[i][0] = dis[i][0];
		}
		for (int i = 1; i < count; i++) {
			for (int j = 1; j < N; j++) {
				for (int k = 1; k < N; k++) {
					if ((1 << (k - 1)) & i) {		//�ж�k�Ƿ��ڼ���i��
						dp[j][i] = min(dp[j][i], dis[j][k] + dp[k][i - (1 << (k - 1))]);		//״̬ת��
					}
				}
			}
		}
		double a = 10e7;	//��ʼ����
		for (int i = 1; i < N; i++)
			a = min(a, dp[i][count - 1] + dis[i][N - 1]);	//��Ϊ�յ����ΪN������Ҫѡȡ��С��dp[i][count-1]+dis[i][N-1]
		printf("%.2lf\n", a);
	}
	return 0;
}