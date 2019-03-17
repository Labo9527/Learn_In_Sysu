#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct quarter {
	int start;
	int end;
	double average;
	quarter(){}
};

bool cmp(quarter a, quarter b) {
	if (a.average != b.average)
		return a.average > b.average;
	if (a.end - a.start != b.end - b.start)
		return a.end - a.start > b.end - b.start;
	return a.start < b.start;
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main() {
	int T;
	int Case = 0;
	cin >> T;
	while (T--) {
		int n1, n2, n3;
		int p[1100];
		int count = 0;
		vector<quarter> ps;
		cin >> n1 >> n2 >> n3;
		for (int i = 0; i < n1; i++)
			cin >> p[i];
		for (int i = 0; i < n1; i++) {
			int number = 0;
			for (int j = i; j < n1; j++) {
				number += p[j];
				if (j - i + 1 >= n3) {
					quarter a;
					ps.push_back(a);
					ps[count].start = i;
					ps[count].end = j;
					ps[count].average = (number+0.00) / (j - i + 1);
					count++;
				}
			}
		}
		sort(ps.begin(), ps.end(), cmp);
		cout << "Result for run " << ++Case << ":" << endl;
		int X = min(n2, count);
		for (int i = 0; i < X; i++)
			cout << ps[i].start + 1 << "-" << ps[i].end + 1 << endl;
	}
	return 0;
}