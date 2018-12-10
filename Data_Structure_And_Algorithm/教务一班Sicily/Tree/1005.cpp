#include <iostream>
#include <queue>

using namespace std;

template <typename T> struct BinaryNode {
	T elem;
	BinaryNode *left;
	BinaryNode * right;
	BinaryNode(T d, BinaryNode *l = NULL, BinaryNode *r = NULL) :elem(d), left(l), right(r) {};
};

template <typename T>
void levelTraversal(BinaryNode<T>* root, void(*visit)(T &x)) {
	if (root == NULL)
		return;
	queue<BinaryNode<T>*> Book;
	Book.push(root);
	while (!Book.empty()) {
		root = Book.front();
		Book.pop();
		visit(root->elem);
		if (root->left != NULL)
			Book.push(root->left);
		if (root->right != NULL)
			Book.push(root->right);
	}
}

template<typename T>
void Print(T &x) {
	cout << x << endl;
}

int main() {
	void(*fun)(int&);
	fun = Print;
	BinaryNode<int> *root1 = new BinaryNode<int>(1);
	BinaryNode<int> *root2 = new BinaryNode<int>(2);
	BinaryNode<int> *root3 = new BinaryNode<int>(3);
	BinaryNode<int> *root4 = new BinaryNode<int>(4);
	BinaryNode<int> *root5 = new BinaryNode<int>(5);
	root1->left = root2;
	root1->right = root3;
	root2->left = root4;
	root2->right = root5;
	levelTraversal(root1, fun);
	return 0;
}