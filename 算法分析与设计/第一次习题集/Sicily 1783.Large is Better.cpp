#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string Xiaosmall(string a) {
	string res;
	vector<char> k;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '0') {
			sort(k.begin(), k.end());
			for (int j = k.size()-1; j >=0 ; j--)
				res += k[j];
			res += '0';
			k.clear();
		}
		else
			k.push_back(a[i]);
	}
	sort(k.begin(), k.end());
	for (int j = k.size() - 1; j >= 0; j--)
		res += k[j];
	k.clear();
	return res;
}

int main() {
	int T;
	string number;
	cin >> T;
	while (T--) {
		cin >> number;
		cout << Xiaosmall(number) << endl;
	}
	return 0;
}