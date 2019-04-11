#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double x[110];

int main() {
	int n;	//https://blog.csdn.net/dark_dawn/article/details/81415746
			//参考了以上blog的数学证明
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x, x + n);
		printf("%.4lf ", (x[0] + x[n - 1]) / 2);
		double ans = 1;
		for (int i = 0; i < n - 1; i++)
			ans = ans + sqrt(4 - pow((x[i + 1] - x[i]) / 2, 2));
		printf("%.4lf\n", ans);
	}
	return 0;
}