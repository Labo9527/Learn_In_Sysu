#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct child {
	long long int a;
	long long int b;
	child() {};
	child(long long int i,long long int j) :a(i), b(j) {};
};

bool cmp(child a, child b) {
	return a.b < b.b;
}

int main() {
	long long int n, s;
	while (cin >> n >> s,n!=0) {
		vector<child> p;
		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			p.push_back(child(a, b));
		}
		sort(p.begin(), p.end(), cmp);
		vector<child>::iterator it;
		for (it = p.begin(); it != p.end(); it++) {
			if (s >= it->b)
				s = s + it->a;
			else
				break;
		}
		if (it == p.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}