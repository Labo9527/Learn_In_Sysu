#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int time = 0;
		vector<int> tasks;
		int k;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> k;
			tasks.push_back(k);
		}
		while (tasks.size()) {
			int s = tasks[0];
			tasks.erase(tasks.begin());
			bool ok = true;
			for (int i = 0; i < tasks.size(); i++)
				if (s < tasks[i])
					ok = false;
			if (ok == false)
				tasks.push_back(s);
			else {
				time++;
				if (m == 0) {
					cout << time << endl;
					break;
				}
			}
			m--;
			if (m < 0)
				m = tasks.size() - 1;
		}
	}
	return 0;
}