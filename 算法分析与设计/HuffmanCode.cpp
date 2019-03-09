#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	char number;
	int frequency;
	node(char a, int b) :number(a), frequency(b) {
	};
	node():number(0),frequency(0) {
	};
};

struct cmp {
	bool operator()(node a, node b) {
		return a.frequency > b.frequency;
	}
};

int main() {
	int n;
	while (cin >> n) {
		priority_queue<node, vector<node>, cmp> p;
		int B = 0;
		char a;
		int b;
		for (int i = 0; i < n; i++) {
		    cin>>a>>b;
			node sample(a,b);
			p.push(sample);
		}
		while (p.size() > 1) {
			node k1 = p.top();
			p.pop();
			node k2 = p.top();
			p.pop();
			B = B + k1.frequency + k2.frequency;
			node k3('f', k1.frequency + k2.frequency);
			p.push(k3);
		}
		cout << B << endl;
	}
	return 0;
}