#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node{
	int myAttr;
	int pos;
};

bool cmp(node a, node b) {
	return a.pos < b.pos;
}

int main() {
	int n;
	while (cin >> n && n) {
		stack<node> peoples;
		vector<node> man;
		vector<node> woman;
		node a, b;
		for (int i = 0; i < n; i++) {
			cin >> a.pos >> b.pos;
			a.myAttr = b.myAttr = i;
			man.push_back(a);
			woman.push_back(b);
		}
		sort(man.begin(), man.end(), cmp);
		sort(woman.begin(), woman.end(), cmp);
		int i = 0;
		int j = 0;
		for (; i < n&&j < n;) {
			if (woman[i].pos < man[j].pos) {
				if (!peoples.empty() && peoples.top().myAttr == woman[i].myAttr) {
					peoples.pop();
					i++;
					continue;
				}
				peoples.push(woman[i++]);
			}
			else {
				if (!peoples.empty() && peoples.top().myAttr == man[j].myAttr) {
					peoples.pop();
					j++;
					continue;
				}
				peoples.push(man[j++]);
			}
		}
		while (i < n) {
			if (!peoples.empty() && peoples.top().myAttr == woman[i].myAttr) {
				peoples.pop();
				i++;
				continue;
			}
			peoples.push(woman[i++]);
		}
		while (j < n) {
			if (!peoples.empty() && peoples.top().myAttr == man[j].myAttr) {
				peoples.pop();
				j++;
				continue;
			}
			peoples.push(man[j++]);
		}
		if (peoples.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}