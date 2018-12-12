#include <iostream>

using namespace std;

struct node{
	int val;
	node* next;
	node(int a=0, node* b = NULL) {
		val = a;
		next = b;
	}
};

void traverse(node* r) {
	bool flag = false;
	while (r != NULL) {
		if (flag)
			cout << " ";
		cout << r->val;
		flag = true;
		r = r->next;
	}
	if (flag == false)
		cout << "NULL";
}

int main() {
	int n;
	while (cin >> n&&n != 0) {
		int num;
		node* hast1[13];
		node* hast2[13];
		for (int i = 0; i < 13; i++) {
			hast2[i] = hast1[i] = new node();
		}
		for (int i = 0; i < n; i++) {
			cin >> num;
			int k = num % 13;
			hast2[k]->next = new node(num);
			hast2[k] = hast2[k]->next;
		}
		for (int i = 0; i < 13; i++) {
			cout << i << "#";
			traverse(hast1[i]->next);
			cout << endl;
		}
	}
	return 0;
}