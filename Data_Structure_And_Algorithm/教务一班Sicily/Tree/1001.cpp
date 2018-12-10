#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>

using namespace std;

int Ans(int a, int b) {
	if (a == b)return a;
	if (a > b) return Ans(a>>1, b);
	else return Ans(a, b>>1);
}

int main() {	//完全二叉树上一个结点为1/2
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", Ans(a, b));
	}
	return 0;
}