#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int index;
	int priority;
};

struct cmp1{
	bool operator()(node &n1, node &n2){
		return n1.priority > n2.priority;
	}
};

priority_queue<node, vector<node>, cmp1> seq;

struct entry{
	int index;
	int column[11];
};

struct cmp2 {
	bool operator()(entry &e1, entry &e2) {
		priority_queue<node, vector<node>, cmp1> original = seq;
		while (!original.empty()) {
			if (e1.column[original.top().index] != e2.column[original.top().index])
				return e1.column[original.top().index] > e2.column[original.top().index];
			else
				original.pop();
		}
		return e1.index > e2.index;
	}
};



int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<entry> v;
		for (int i = 0; i < n; i++) {
			entry t;
			for (int j = 0; j < m; j++)
				cin >> t.column[j];
			t.index = i;
			v.push_back(t);
		}
		int q;
		cin >> q;
		while (q--) {
			while (!seq.empty())
				seq.pop();
			for (int i = 0; i < m; i++) {
				node t;
				cin >> t.priority;
				t.index = i;
				seq.push(t);
			}
			priority_queue<entry, vector<entry>, cmp2> Q(v.begin(), v.end());
			while (!Q.empty()) {
				cout << Q.top().index;
				if (Q.size() != 1)
					cout << " ";
				Q.pop();
			}
			cout << endl;
		}
	}
	return 0;
}