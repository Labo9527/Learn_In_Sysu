#include <iostream>

using namespace std;

int n, k, temp;
int A[10000005];
int h[20000005] = { 0 };//有毛区别啊？ 这一行变成h[1000000005]就不行？//我觉得之前一直TLE是主元没选好

void swap(int *a, int *b) {
	if (a != b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int partion(int s, int e) {
	int j = s - 1;
	for (int i = s; i < e; i++) {
		if (A[i] < A[e] && i != j) {		//全顺序这条if不会执行，该partion以A[e]分界，返回A[e]的位置
			j++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[j + 1], &A[e]);
	return j + 1;
}

int quick(int s, int e) {
	int m = partion(s, e);
	if (m == k)return A[m];
	else if (m > k) return quick(s, m - 1);
	else return quick(m + 1, e);
}

int main() {
	int count = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (!h[temp+ 10000000]) {
			h[temp+ 10000000] = 1;
			A[count++] = temp;
		}
	}
	k = count - k;
	cout << quick(0, count - 1) << endl;
	return 0;
}