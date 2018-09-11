#include <iostream>
#include <vector>

using namespace std;

__int64 fib1(int n) {//T(n)=O(2^n)
	if (n < 2)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

__int64 fib2(int n, int &prev) {//T(n)=O(n) S(n)=O(n)
	if (n == 0) {
		prev = 1;//fib(-1)=1
		return 0;
	}
	else {
		int prevPrev; prev = fib2(n - 1, prevPrev);
		return prev + prevPrev;
	}
}

__int64 fib3(int n) {//T(n)=O(n) S(n)=O(1)
	__int64 f = 0, g = 1;
	while (n-- > 0) {
		g += f;
		f = g - f;
	}
	return f;
}

int main() {
	for (int i = 0; i < 10; i++)
		cout << i << ":" << fib1(i) << endl;
	cout << "--------------" << endl;
	int k;
	for (int i = 0; i < 10; i++)
		cout << i << ":" << fib2(i,k) << endl;
	cout << "--------------" << endl;
	for (int i = 0; i < 10; i++)
		cout << i << ":" << fib3(i) << endl;
	return 0;
}