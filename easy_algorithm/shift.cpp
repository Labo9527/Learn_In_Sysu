#include <iostream>
#include <stack>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void reverse(int* A, int lo, int hi) {
	if (lo < hi) {
		swap(A[lo], A[hi]);
		reverse(A, lo + 1, hi - 1);
	}
}
int shift2(int* A, int n, int k) {
	k %= n;
	reverse(A, 0, k - 1);//½«A[0,k)µ¹ÖÃ
	reverse(A, k, n - 1);//½«A[k,n)µ¹ÖÃ
	reverse(A, 0, n - 1);//½«A[0,n)µ¹ÖÃ
	return 3 * n;
}
int main() {
	int A[6];
	for (int i = 1; i <= 6; i++)
		A[i-1] = i;
	shift2(A, 6, 2);
	for (int i = 0; i < 6; i++)
		cout << A[i] << endl;
	return 0;
}