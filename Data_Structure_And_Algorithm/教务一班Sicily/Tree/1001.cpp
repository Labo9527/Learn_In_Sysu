#include <iostream>

using namespace std;

int Ans(int a, int b) {
	if (a == b)return a;
	if (a > b) return Ans(a / 2, b);
	else return Ans(a, b / 2);
}

int main() {	//完全二叉树上一个结点为1/2
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << Ans(a, b) << endl;
	}
	return 0;
}