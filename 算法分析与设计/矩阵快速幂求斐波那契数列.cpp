#include <iostream>

using namespace std;

#define MOD 1000000007

struct matrix {
	long long int data[2][2];		//long long 很关键
};

matrix base;
matrix ans;

matrix multi(matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans.data[i][j] = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans.data[i][j] += a.data[i][k] * b.data[k][j];
				ans.data[i][j] = ans.data[i][j] % MOD;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	while (cin >> n) {
		ans.data[0][0] = 1;
		ans.data[0][1] = 0;
		ans.data[1][0] = 0;
		ans.data[1][1] = 1;	//专门做成单位阵
		base.data[0][0] = 1;
		base.data[0][1] = 1;
		base.data[1][0] = 1;
		base.data[1][1] = 0;
		while (n) {
			if (n % 2 == 0) {
				base = multi(base, base);
				n /= 2;
			}
			else if (n % 2 == 1) {
				ans = multi(ans, base);
				n--;
			}
		}
		cout << ans.data[0][1]%MOD << endl;
	}
	return 0;
}
