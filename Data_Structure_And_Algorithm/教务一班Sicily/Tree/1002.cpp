#include <iostream>
#include <string>

using namespace std;

struct Node {
	Node*left;
	Node*Right;
	char val;
	Node(char val, Node* left, Node *Right) :val(val), left(left), Right(Right) {};
	Node() { left = nullptr; Right = nullptr; };
};

Node root;

void CreateTree(string pre, string inorder, Node* now) {
	now->val = pre[0];
	string s1, s2, s3, s4;
	int i;
	for (i = 0; i < inorder.length(); i++) {
		if (inorder[i] == pre[0])
			break;
		s3 += inorder[i];
	}
	i++;
	for (; i < inorder.length(); i++)
		s4 += inorder[i];
	for (int j = 0; j < s3.length(); j++) {
		s1 += pre[1 + j];
	}
	for (int j = 0; j < s4.length(); j++) {
		s2 = pre[pre.length() - 1 - j] + s2;
	}
	if (s3.length()) {
		Node *Left = new Node();
		now->left = Left;
		CreateTree(s1, s3, Left);
	}
	if (s4.length()) {
		Node *Right = new Node();
		now->Right = Right;
		CreateTree(s2, s4, Right);
	}
}

void PostTraverse(Node *p) {
	if (p->left != nullptr)
		PostTraverse(p->left);
	if (p->Right != nullptr)
		PostTraverse(p->Right);
	cout << p->val;
}

int main() {
	string pre, inorder;
	cin >> pre >> inorder;
	CreateTree(pre, inorder, &root);
	PostTraverse(&root);
	cout << endl;
	return 0;
}