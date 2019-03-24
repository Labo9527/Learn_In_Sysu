#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int n;
long long int sum;
int nums[1010];
int res[1010][1010];

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int cal(int start, int end) {
	if (start > end)
		return 0;
	if (start == end)
		return res[start][end] = nums[start];
	if (res[start][end] != -1)
		return res[start][end];
	int val1 = nums[start] + (nums[start + 1] >= nums[end] ? cal(start + 2, end) : cal(start + 1, end - 1));
	int val2 = nums[end] + (nums[end - 1] > nums[start] ? cal(start, end - 2) : cal(start + 1, end - 1));
	res[start][end] = max(val1, val2);
	return res[start][end];
}

int main() {
	int T = 0;
	while (cin >> n && n) {
		memset(res, -1, sizeof(res));
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			sum += nums[i];
		}
		cout << "In game " << ++T << ", the greedy strategy might lose by as many as " << 2*cal(0, n - 1)-sum << " points." << endl;
	}
	return 0;
}