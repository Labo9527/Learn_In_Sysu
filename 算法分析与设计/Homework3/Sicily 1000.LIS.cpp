#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

int main() {
	int N;
	int nums[5010];
	int dp[5010];
	int max, end;
	while (cin >> N) {
		max = -1;
		end = 0;
		memset(dp, -1, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] <= nums[i] && dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
			if (dp[i] == -1)
				dp[i] = 1;
			if (dp[i] > max) {
				max = dp[i];
				end = i;
			}
			else if (dp[i] == max && nums[i] < nums[end]) {
				max = dp[i];
				end = i;
			}
		}
		cout << max << " " << nums[end] << endl;
	}
	return 0;
}