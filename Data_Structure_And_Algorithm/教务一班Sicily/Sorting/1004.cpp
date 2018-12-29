#include <iostream>
#include <string.h>

using namespace std;



int main() {
	int c, n;
	while (cin >> c >> n) {
		int *a=new int[n];
		bool *b=new bool[c+1];
		int m = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		memset(b, false, sizeof(bool)*(c+1));
		for (int i = n - 1; i >= 0; i--) {
			if (b[a[i]] == false) {
				b[a[i]] = true;
				m++;
			}
			else
				a[i] = 0;
		}
		cout << m << endl;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] != 0 && cnt == m)
				cout << a[i] << endl;
			else if (a[i] != 0) {
				cout << a[i] << " ";
				cnt++;
			}
		}
		delete[]a;
		delete[]b;
	}
	return 0;
}