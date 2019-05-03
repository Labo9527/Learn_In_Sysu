#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(long long a) {
	if (a == 2)
		return true;
	for (long long int i = 2; i*i <= a; i++)
		if (a%i == 0)
			return false;
	return true;
}

int main() {
/*
	for (int i = 2; i < 64; i++) {
		long long int n = (long long)pow(2.0, i) - 1;
		if (isPrime(i) && !isPrime(n))
			cout << i << endl;
	}
输出
11
23
29
37
41
43
47
53
59	先寻找64内符合要求的数字，不然会超时
*/
	int k;
	int nums[9] = { 11,23,29,37,41,43,47,53,59 };
	cin >> k;
	for (int i = 0; i < 9 && nums[i] <= k; i++) {
		vector<long long> ans;
		long long a = 2;
		long long n = (long long)pow(2,nums[i] ) - 1;
		long long temp = n;
		while (a*a <= n) {
			if (n%a == 0) {
				ans.push_back(a);
				n /= a;
			}
			a++;
		}
		ans.push_back(n);
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout << " * " << ans[i];
		}
		cout << " = "<< temp << " = ( 2 ^ " << nums[i] << " ) - 1" << endl;
	}
	return 0;
}