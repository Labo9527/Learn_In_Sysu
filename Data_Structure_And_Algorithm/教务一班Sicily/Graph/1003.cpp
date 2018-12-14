#include <iostream>

#define MAX_SIZE 1000010

using namespace std;


int a, b;
int root[MAX_SIZE];

int find(int t) {
	return (t == root[t]) ? t : (root[t] = find(root[t]));
}

int main() {
	for (int i = 0; i < MAX_SIZE; i++)
		root[i] = i;
	while (cin >> a >> b) {
		int p = find(a);
		int q = find(b);
		if (p != q) {
			cout << a << " " << b << endl;
			root[p] = root[q];//而不是root[a]=root[b]，因为要从根并，而不是节点并
		}
	}
	return 0;
}