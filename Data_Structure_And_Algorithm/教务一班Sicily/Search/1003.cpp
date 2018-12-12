#include <iostream>

using namespace std;

struct node{
	int key;
	int height;
	node *left;
	node *right;
	node(int val, node* l = NULL, node* r = NULL) {
		key = val;
		left = l;
		right = r;
		height = 1;
	}
};

int getheight(node *temp) {
	if (temp == NULL)
		return 0;
	return temp->height;
}

int max(int a, int b) {
	if (a >= b)
		return a;
	else return b;
}

node *RR(node* root) {
	node* p = root->right;
	root->right = p->left;
	p->left = root;
	p->height = max(getheight(p->left), getheight(p->right)) + 1;
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	return p;
}

node *LL(node *root) {
	node*p = root->left;
	root->left = p->right;
	p->right = root;
	p->height = max(getheight(p->left), getheight(p->right)) + 1;
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
	return p;
}

node *RL(node* root) {
	root->right = LL(root->right);
	return RR(root);
}

node *LR(node* root) {
	root->left = RR(root->left);
	return LL(root);
}

void insert(node* &root, int value) {
	if (root == NULL) {
		root = new node(value);
		root->height = 1;
	}
	else {
		if (value > root->key) {
			insert(root->right, value);
			if (getheight(root->right) > getheight(root->left) + 1) {
				if (value > root->right->key) root = RR(root);
				else root = RL(root);
			}
		}
		else if (value < root->key) {
			insert(root->left, value);
			if (getheight(root->left) > getheight(root->right) + 1) {
				if (value < root->left->key) root = LL(root);
				else root = LR(root);
			}
		}
	}
	root->height = max(getheight(root->left),getheight(root->right)) + 1;
}

void preorder(node* root) {
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	int T, n, num;
	cin >> T;
	while (T--) {
		cin >> n;
		node *root = NULL;
		for (int i = 0; i < n; i++) {
			cin >> num;
			insert(root, num);
		}
		preorder(root);
		cout << endl;
	}
	return 0;
}