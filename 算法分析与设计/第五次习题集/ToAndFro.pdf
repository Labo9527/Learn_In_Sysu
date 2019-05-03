#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n;
	string matrix[100][100];
	while (cin >> n, n) {
		string sample;
		int a, b;
		cin >> sample;
		int count = 0;
		while (count < sample.length()) {
			if ((count / n) % 2 == 0) {
				for (int i = 0; i < n; i++) {
					matrix[count / n][i] = sample[count];
					count++;
				}
			}
			else {
				for (int i = n - 1; i >= 0; i--) {
					matrix[count / n][i] = sample[count];
					count++;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < sample.length() / n; i++)
				cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}