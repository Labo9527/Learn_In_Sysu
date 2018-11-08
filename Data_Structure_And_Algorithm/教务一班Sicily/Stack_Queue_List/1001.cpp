#include <iostream>
#include <string>

using namespace std;

void reverse(string sample) {
	for (int i = 0; i < sample.length(); i++)
		cout << sample[sample.length() - 1 - i];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string sample;
		cin >> sample;
		int index = 0;
		for (int i = 0; i < sample.length(); i++) {
			if (sample[i] == '_') {
				string K = sample.substr(index, i - index);
				reverse(K);
				index = i + 1;
				cout << "_";
			}
			else if (i == sample.length() - 1) {
				string K = sample.substr(index, i - index + 1);
				reverse(K);
				index = i + 1;
			}
		}
		cout << endl;
	}
	return 0;
}