#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> b;
		string x;
		int k;
		for (int i = 0; i < n; i++) {
			cin >> k;
			b.push_back(k);
		}
		cin >> x;
		cout << "(";
		for (int i = 0; i < n; i++) {
			int res = 0;
			for (int j = 0; j < x.length(); j++) {
				res = (res * 10 + x[j] - '0') % b[i];
			}
			cout << res;
			if (i != n - 1)
				cout << ",";
		}
		cout << ")" << endl;
	}
	return 0;
}