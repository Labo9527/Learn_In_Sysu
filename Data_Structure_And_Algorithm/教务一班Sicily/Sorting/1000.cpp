#include <iostream>

using namespace std;

int num[110];
int L[110];
int R[110];
int n;

void Left() {
	L[0] = -9999999;
	for (int i = 1; i < n; i++) {
		L[i] = (num[i - 1] > L[i - 1]) ? num[i - 1] : L[i - 1];
	}
}

void Right() {
	R[n - 1] = 9999999;
	for (int i = n - 2; i >= 0; i--) {
		R[i] = (num[i + 1] < R[i + 1]) ? num[i + 1] : R[i + 1];
	}
}

int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> num[i];
		Left();
		Right();
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (num[i] > L[i] && num[i] < R[i])
				count++;
		}
		cout << count << endl;
	}
	return 0;
}