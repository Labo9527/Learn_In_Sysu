#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a[110];
int s[11000];	//参考了http://www.cppblog.com/powerwater/articles/187391.html
//压缩后最大为11000
int res[11000];

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int main() {
	int L, S, T, M;
	cin >> L >> S >> T >> M;
	a[0] = 0;
	a[M + 1] = L;
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= M; i++)
		cin >> a[i];
	sort(a, a + M + 2);
	if (S == T) {
		int r = 0;
		for (int i = 1; i <= M; i++)
			if (a[i] % S == 0)
				r++;
		cout << r << endl;
	}
	else {
		int d = 0;
		int threshold = S*T;
		int x;
		for (int i = 1; i <= M + 1; i++) {
			x = a[i] - a[i - 1] - d;
			if (x > threshold) d = d + x - threshold;
			a[i] = a[i] - d;
			s[a[i]] = 1;
		}
		s[a[M + 1]] = 0;
		res[0] = 0;
		for (int i = 1; i <= a[M + 1] + T - 1; i++) {	//最后一次落脚点a[m+1]+t-1
			res[i] = 0x3f3f3f3f;
			for (int j = S; j <= T; j++)
				if (i >= j)
					res[i] = min(res[i], res[i - j]);
			res[i] += s[i];
		}
		int r = 0x3f3f3f3f;
		for (int i = a[M + 1]; i <= a[M + 1] + T - 1; i++)
			r = min(r, res[i]);
		cout << r << endl;
	}
	return 0;
}