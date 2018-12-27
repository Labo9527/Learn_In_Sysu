#include <iostream>

using namespace std;

int num[1010];
int n;

void sort(int l,int r) {
	if (l < r) {
		int i = l, j = r, x = num[l];
		while (i < j) {
			while (i < j&&num[j] >= x)
				j--;
			if (i < j)
				num[i++] = num[j];
			while (i < j&&num[i] < x)
				i++;
			if (i < j)
				num[j--] = num[i];
		}
		num[i] = x;
		sort(l, i - 1);
		sort(i + 1, r);
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		sort(0, n - 1);
		for (int i = 0; i < n; i++)
			cout << num[i] << endl;
	}
	return 0;
}