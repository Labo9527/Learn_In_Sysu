#include <iostream>

using namespace std;

int main() {
	int T;
	int array[25];
	cin >> T;
	while (T--) {
		int n;
		int count = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> array[i];
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (array[i] - 2 * array[j] == 0 || array[j] - 2 * array[i] == 0)
					count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}