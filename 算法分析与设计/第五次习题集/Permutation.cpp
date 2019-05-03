#include <iostream>

using namespace std;

int main() {
	int res[110][110] = { {0} };
	res[1][0] = 1;
	for (int i = 1; i < 100; i++)
		for (int j = 0; j < i; j++) {
			res[i + 1][j] += (res[i][j] * (j + 1));
			res[i + 1][j + 1] += res[i][j] * (i - j);
			res[i + 1][j] %= 2007;
			res[i + 1][j + 1] %= 2007;	//动态转移方程参考了PPT，思路是新插入的数必定是最大的数，所以新增小于号的话肯定是在队列最右或者大于号处插入，新增大于号类似
		}
	int n, k;
	while (cin >> n >> k) {
		cout << res[n][k] << endl;
	}
	return 0;
}