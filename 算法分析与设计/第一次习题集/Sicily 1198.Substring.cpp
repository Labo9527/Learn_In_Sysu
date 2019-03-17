#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string res;
		string s[10];
		int visit[10];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			visit[i] = 0;
		}
		sort(s, s + n, cmp);
		for (int i = 0; i < n; i++)
			res += s[i];
		cout << res << endl;
	}
	return 0;
}