#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

int main() {
	int T;
	int Case = 0;
	cin >> T;
	while (T--) {
		int n, m;
		long long int s[15][2010];
		memset(s, 0, sizeof(s));
		int threshold[11];
		cin >> n >> m;
		for (int i = 0; i < 11; i++) {
			threshold[i] = pow(2, i - 1);
		}
		for (int j = 1; j <= m; j++) {
			s[1][j] = j;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j < threshold[i])
					s[i][j] = 0;
				else if(j==threshold[i]){
					s[i][j] = 1;
				}
				else {
					s[i][j] = s[i][j - 1] + s[i - 1][j / 2];
				}
			}
		}
		cout << "Case " << ++Case << ": n = " << n << ", m = " << m << ", # lists = " << s[n][m] << endl;
	}
	return 0;
}