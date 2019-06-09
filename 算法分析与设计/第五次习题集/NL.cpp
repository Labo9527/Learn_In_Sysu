#include <iostream>
#include <algorithm>

using namespace std;	//本代码参考了 https://blog.csdn.net/dalewzm/article/details/12860803 的DFS思想

int nums[5];
int target;
int res = -1000000;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int divv(int a, int b) {
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	if (b == 0 || a%b)
		return 0x3f3f3f3f;
	return a / b;
}

void update(int num[], int length) {
	for (int i = 0; i < length; i++)
		if (num[i] <= target && num[i] > res)
			res = num[i];
}

void dfs(int num[], int length) {
	update(num, length);
	if (length == 1)
		return;
	for (int i = 0; i<length - 1; i++)
		for (int j = i + 1; j < length; j++) {
			int newnum[5];
			int counter = 0;
			for (int k = 0; k < length; k++)
				if (k != i && k != j)
					newnum[counter++] = num[k];
			for (int k = 0; k < 4; k++) {
				if (k == 0) {
					newnum[counter] = add(num[i], num[j]);
					dfs(newnum, length - 1);
				}
				else if (k == 1) {
					newnum[counter] = sub(num[i], num[j]);
					dfs(newnum, length - 1);
					newnum[counter] = sub(num[j], num[i]);
					dfs(newnum, length - 1);
				}
				else if (k == 2) {
					newnum[counter] = mul(num[i], num[j]);
					dfs(newnum, length - 1);
				}
				else {
					//	if (num[i] == 0 || num[j] == 0)
					//		continue;
					newnum[counter] = divv(num[i], num[j]);
					if (newnum[counter] != 0x3f3f3f3f)
						dfs(newnum, length - 1);
				}
			}
		}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		res = -10000000;
		for (int i = 0; i < 5; i++)
			cin >> nums[i];
		cin >> target;
		dfs(nums, 5);
		cout << res << endl;
	}
	return 0;
}