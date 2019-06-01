#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
public:
	Node() {
		data = 'N';
		par = NULL;
		left = NULL;
		right = NULL;
	};
	Node(unsigned char a, int b) :data(a), frequency(b) { 
		par = NULL;
		left = NULL;
		right = NULL;
	};
	~Node() {};
	void setLeft(Node *a) {
		a->setPar(this);
		left = a;
	}
	void setRight(Node *a) {
		a->setPar(this);
		right = a;
	}
	void setPar(Node *a) {
		par = a;
	}
	void setFrequency(int a) {
		frequency = a;
	}
	void setData(unsigned char a) {
		data = a;
	}
	Node *getLeft() {
		return left;
	}
	Node *getRight() {
		return right;
	}
	Node *getPar() {
		return par;
	}
	unsigned char getData() {
		return data;
	}
	int getFrequency() {
		return frequency;
	}

private:
	unsigned char data;
	int frequency;
	Node *par;
	Node *left;
	Node *right;
};

#endif // !NODE_H
