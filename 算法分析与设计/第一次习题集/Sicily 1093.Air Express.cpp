#include <iostream>

using namespace std;

int lowerbound[4];
int upperbound[4];
int rate[4];
int Size;
int addition;

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int cal() {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (Size >= lowerbound[i] && Size <= upperbound[i]) {
			res = Size * rate[i];
			addition = 0;
		}
		else if (Size < lowerbound[i]) {
			int temp = res;
			res = min(res, lowerbound[i] * rate[i]);
			if (res == lowerbound[i] * rate[i] && res != temp)
				addition = lowerbound[i] - Size;
		}
	}
	return res;
}

int main() {
	int count = 0;
	while (cin >> upperbound[0]) {
		cin >> rate[0] >> upperbound[1] >> rate[1] >> upperbound[2] >> rate[2] >> rate[3];
		cout << "Set number " << ++count << ":" << endl;
		upperbound[3] = 0x3f3f3f;
		lowerbound[0] = 0;
		lowerbound[1] = upperbound[0] + 1;
		lowerbound[2] = upperbound[1] + 1;
		lowerbound[3] = upperbound[2] + 1;
		while (cin >> Size && Size) {
			int money = cal();
			cout << "Weight (" << Size << ") has best price $" << money << " (add " << addition << " pounds)" << endl;
		}
		cout << endl;
	}
	return 0;
}