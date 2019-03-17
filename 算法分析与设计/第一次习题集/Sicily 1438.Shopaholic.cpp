#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		int res = 0;
		vector<int> prices;
		cin >> n;
		int k;
		for (int i = 0; i < n; i++) {
			cin >> k;
			prices.push_back(k);
		}
		sort(prices.begin(), prices.end());
		int count = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (count == 2) {
				count = 0;
				res += prices[i];
			}
			else {
				count++;
			}
		}
		cout << res << endl;
	}
	return 0;
}