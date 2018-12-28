#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	int t;
	//srand(time(NULL));
	while ((cin >> n >> m)&&n&&m) {
		vector<int> num;
		for (int i = 0; i < n; i++) {
			cin >> t;
			num.push_back(t);
		}
		sort(num.begin(),num.end());
		for (int i = 0; i < n; i += m) {
			cout << num[i];
			if (i + m < n)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}