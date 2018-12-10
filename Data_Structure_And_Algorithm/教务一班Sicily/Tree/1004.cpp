#include <iostream>
#include <stack>

using namespace std;

template <typename T> struct BinaryNode {
	T elem;
	BinaryNode *left;
	BinaryNode * right;
	BinaryNode(T d, BinaryNode *l = NULL, BinaryNode *r = NULL) :elem(d), left(l), right(r) {};
};

template <typename T>
void inorder_recursive(BinaryNode<T>* root, void(*visit)(T &x)) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		inorder_recursive(root->left, visit);
	visit(root->elem);
	if (root->right != NULL)
		inorder_recursive(root->right, visit);
}

template <typename T>
void inorder(BinaryNode<T>* root, void(*visit)(T &x)) {
	if (root == NULL)
		return;
	stack<BinaryNode<T>*> Book;
	while (root != NULL || !Book.empty()) {
		while (root != NULL) {
			Book.push(root);
			root = root->left;
		}
		if (!Book.empty()) {
			root = Book.top();
			Book.pop();
			visit(root->elem);
			root = root->right;
		}
	}
}

template <typename T>
void Print(T &x) {
	cout << x << endl;
}

int main() {
	void(*fun)(int &x) = Print;
	BinaryNode<int> *root1 = new BinaryNode<int>(1);
	BinaryNode<int> *root2 = new BinaryNode<int>(2);
	BinaryNode<int> *root3 = new BinaryNode<int>(3);
	BinaryNode<int> *root4 = new BinaryNode<int>(4);
	BinaryNode<int> *root5 = new BinaryNode<int>(5);
	root1->left = root2;
	root1->right = root3;
	root2->left = root4;
	root2->right = root5;
	inorder_recursive(root1, fun);
	cout << "-------------------" << endl;
	inorder(root1, fun);
	return 0;
}