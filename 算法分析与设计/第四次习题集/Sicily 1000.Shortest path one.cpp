#include <iostream>
#include <string.h>

#define MAX 1000000

using namespace std;

struct road {
	int start;
	int end;
	int cost;
	road(int a = 0, int b = 0, int c = 0) :start(a), end(b), cost(c) {};
};

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main() {
	int n, k;
	int d[200];
	road r[4010];
	while (cin >> n >> k) {
		int NF = 0;
		for (int i = 0; i < 200; i++)
			d[i] = MAX;
		for (int i = 1; i <= k; i++)
			cin >> r[i].start >> r[i].end >> r[i].cost;
		d[1] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j <= k; j++) {
				d[r[j].end] = min(d[r[j].end], d[r[j].start] + r[j].cost);
			}
		}
		int temp = d[n];
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j <= k; j++) {
				d[r[j].end] = min(d[r[j].end], d[r[j].start] + r[j].cost);
			}
		}
		if (temp!=d[n]) {
			cout << 0 << endl;
			continue;
		}
		else {
			if (d[n] < MAX)
				cout << d[n] << endl;
			else
				cout << -1 << endl;
		}
	}
	return 0;
}