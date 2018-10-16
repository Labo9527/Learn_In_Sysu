#include <iostream>
#include <string>

using namespace std;

bool Map(string a, string b) {
	if (a.length() != b.length())
		return false;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'A'&&b[i] == 'T')
			continue;
		else if (a[i] == 'T'&&b[i] == 'A')
			continue;
		else if (a[i] == 'C'&&b[i] == 'G')
			continue;
		else if (a[i] == 'G'&&b[i] == 'C')
			continue;
		return false;
	}
	return true;
}

int main() {
	int T;
	string Book[110];
	int used[110];
	cin >> T;
	while (T--) {
		int n;
		int count = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> Book[i];
			used[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (Map(Book[i], Book[j]) && !used[i]&&!used[j]) {
					count++;
					used[j]=used[i] = 1;
					break;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}