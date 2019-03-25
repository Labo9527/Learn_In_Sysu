#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main() {
	int n;
	double b, r, v, e, f;
	while (cin >> n && n) {
		int a[110];
		double s[110];
		double t[10010];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cin >> b >> r >> v >> e >> f;
		s[0] = 0;
		a[0] = 0;
		t[0] = 0;
		for (int i = 0; i < a[n]; i++) {
			if (i >= r) {
				t[i + 1] = t[i] + 1 / (v - e * (i - r));
			}
			else {
				t[i + 1] = t[i] + 1 / (v - f * (r - i));
			}
		}
		for (int i = 1; i <= n; i++) {
			s[i] = t[a[i]];
			for (int j = 1; j < i; j++) {
				if (s[i] > s[j] + t[a[i] - a[j]] + b)
					s[i] = s[j] + t[a[i] - a[j]] + b;
			}
		}
		printf("%.4lf\n", s[n]);
	}
	return 0;
}