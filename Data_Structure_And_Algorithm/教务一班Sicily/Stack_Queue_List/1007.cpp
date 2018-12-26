#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		int min = 1;
		int max = 0;
		int max_pos = 0;
		int jobs[110];
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> jobs[i];
			if (max < jobs[i]) {
				max = jobs[i];
				max_pos = i;
			}
		}
		while (max_pos != m) {
			jobs[max_pos++] = max = -1;
			int j = max_pos%n;
			for (int k = 0; k < n; k++) {
				if (max < jobs[j]) {
					max = jobs[j];
					max_pos = j;
				}
				j = (j + 1) % n;
			}
			min++;
		}
		cout << min << endl;
	}
	return 0;
}