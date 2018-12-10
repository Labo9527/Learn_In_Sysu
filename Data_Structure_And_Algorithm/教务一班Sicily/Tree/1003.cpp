#include <iostream>

using namespace std;

int CountLeft, CountRight;

int main() {
	int T;
	int K = 1;
	cin >> T;
	while (K <= T) {
		int L, R;
		cin >> L >> R;
		CountLeft = 0;
		CountRight = 0;
		while (L != 1 || R != 1) {
			if (L >= R) {
				L = L - R;
				CountLeft++;
			}
			else {
				R = R - L;
				CountRight++;
			}
		}
		cout << "Scenario #" << K << ":" << endl;
		cout << CountLeft << " " << CountRight << endl;
		K++;
	}
	return 0;
}