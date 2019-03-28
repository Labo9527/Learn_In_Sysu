#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[330];
int s[330][330];

int dp(int i, int j) {
	if (s[i][j] != -1)
		return s[i][j];
	if (i == j)
		return s[i][j] == 0;
	int t = 0;
	for (int k = i; k < j; k++) {
		if (t < dp(i, k) + dp(k + 1, j) + a[i] * a[j + 1] * a[k + 1])
			t = dp(i, k) + dp(k + 1, j) + a[i] * a[j + 1] * a[k + 1];	//DP函数的递归写法参考了https://blog.csdn.net/light_14/article/details/50947319?locationNum=6&fps=1
	}
	return s[i][j] = t;
}


int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[n + i] = a[i];
		}
		memset(s, -1, sizeof(s));
		int res = -1;
		for (int i = 1; i <= n; i++) {
			if (dp(i, i + n - 1) > res)
				res = dp(i, i + n - 1);
		}
		cout << res << endl;
	}
	return 0;
}