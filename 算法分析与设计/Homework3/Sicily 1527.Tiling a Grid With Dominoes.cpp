#include <iostream>

using namespace std;

int main() {
	int N;
	int W;
	cin >> N;
	int dp[1010][20];
	//�ο���CSDN https://www.cnblogs.com/chenximcm/p/6285143.html ��״̬ת�Ƶ��뷨
	dp[1][0] = 1;	//��
	dp[1][1] = dp[1][2] = 1;	//����
	dp[1][3] = 0;	//��
	dp[1][4] = 1;	//��
	dp[1][5] = 1;	//��
	for (int i = 2; i <= 1000; i++) {	//������������������ɫ����
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