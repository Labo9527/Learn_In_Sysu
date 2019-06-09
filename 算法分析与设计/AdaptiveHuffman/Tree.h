#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class tree {
public:
	tree() {	//默认构造函数
		root = new Node();
		root->setData('N');
		root->setFrequency(0);
	}
	void insert(unsigned char t) {	//插入新节点
		Node *NYT = findNYT();
		Node *l = new Node();
		l->setFrequency(0);
		Node *r = new Node(t, 1);
		NYT->setFrequency(1);
		NYT->setLeft(l);
		NYT->setRight(r);
	}
	void correct_frequency(Node *t) {	//用DFS来校正所有频次
		int a = 0, b = 0;
		if (t->getLeft() != NULL) {
			correct_frequency(t->getLeft());
			a = t->getLeft()->getFrequency();
		}
		if (t->getRight() != NULL) {
			correct_frequency(t->getRight());
			b = t->getRight()->getFrequency();
		}
		if (a != 0 || b != 0)
			t->setFrequency(a + b);
	}
	Node *FindString(Node *r, string s) {	//找出某个编码是否有对应的叶子节点
		if (s.length() == 0 && r->getLeft() == NULL&&r->getRight() == NULL)
			return r;
		if (s.length() == 0)
			return NULL;
		if (s[0] == '0')
			return r->getLeft() == NULL ? NULL : FindString(r->getLeft(), s.substr(1, s.length() - 1));
		if (s[0] == '1')
			return r->getRight() == NULL ? NULL : FindString(r->getRight(), s.substr(1, s.length() - 1));
		/*
		for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
		if (r->getLeft() == NULL)
		return NULL;
		return FindString(r->getLeft(), s.substr(0, s.length() - 1));
		}
		else if (s[i] == '1') {
		if (r->getRight() == NULL) {
		return NULL;
		}
		return FindString(r->getRight(), s.substr(0, s.length() - 1));
		}
		}
		return NULL;
		*/
	}
	void update() {	//更新Huffman树
		bool ok = false;
		while (!ok) {
			ok = true;

			vector<Node*> v;
			queue<Node*> q;
			Node *r = this->root;
			q.push(this->root);
			while (!q.empty()) {
				v.push_back(q.front());
				q.pop();
				if (v[v.size() - 1]->getRight() != NULL)
					q.push(v[v.size() - 1]->getRight());
				if (v[v.size() - 1]->getLeft() != NULL)
					q.push(v[v.size() - 1]->getLeft());
			}

			for (int i = v.size() - 1; i >= 0; i--) {
				for (int j = v.size() - 1; j > i; j--) {
					if (v[i]->getFrequency() < v[j]->getFrequency()) {
						ok = false;
						Node *p1 = v[i]->getPar();
						Node *p2 = v[j]->getPar();
						bool one = true;
						bool two = true;
						if (p1->getLeft() == v[i])
							one = true;
						else
							one = false;
						if (p2->getLeft() == v[j])
							two = true;
						else
							two = false;
						if (one) p1->setLeft(v[j]);
						else p1->setRight(v[j]);
						if (two) p2->setLeft(v[i]);
						else p2->setRight(v[i]);
						correct_frequency(this->root);
						break;
					}
				}
				if (ok == false)
					break;
			}

		}
	}
	bool find_code(unsigned char t, Node *r, string &s) {	//找出某个字符的编码
		if (r->getData() == t && r->getFrequency() != 0 && r->getLeft() == NULL && r->getLeft() == NULL)
			return true;
		if (r->getLeft() != NULL&&find_code(t, r->getLeft(), s)) {
			s = '0' + s;
			return true;
		}
		if (r->getRight() != NULL&&find_code(t, r->getRight(), s)) {
			s = '1' + s;
			return true;
		}
		return false;
	}
	bool find_NYT_Code(Node *r, string &s) {
		if (r->getFrequency() == 0 && r->getLeft() == NULL && r->getLeft() == NULL)
			return true;
		if (r->getLeft() != NULL&&find_NYT_Code(r->getLeft(), s)) {
			s = '0' + s;
			return true;
		}
		if (r->getRight() != NULL&&find_NYT_Code(r->getRight(), s)) {
			s = '1' + s;
			return true;
		}
		return false;
	}
	Node *findNYT() {	//找出空节点
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *t = q.front();
			q.pop();
			if (t->getFrequency() == 0 && t->getLeft() == NULL &&t->getRight() == NULL)
				return t;
			if (t->getLeft() != NULL)
				q.push(t->getLeft());
			if (t->getRight() != NULL)
				q.push(t->getRight());
		}
	}
	bool find(unsigned char a) {	//寻找某个字符是否存在
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *t = q.front();
			q.pop();
			if (t->getData() == a&& t->getFrequency() != 0 && t->getLeft() == NULL &&t->getRight() == NULL)
				return true;
			if (t->getLeft() != NULL)
				q.push(t->getLeft());
			if (t->getRight() != NULL)
				q.push(t->getRight());
		}
		return false;
	}
	Node *get(unsigned char a) {	//获取某字符的叶子节点
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *t = q.front();
			q.pop();
			if (t->getData() == a && t->getFrequency() != -1 && t->getLeft() == NULL &&t->getRight() == NULL)
				return t;
			if (t->getLeft() != NULL)
				q.push(t->getLeft());
			if (t->getRight() != NULL)
				q.push(t->getRight());
		}
		return NULL;
	}
	Node *getRoot() {
		return root;
	}
private:
	Node *root;
};

#endif // !TREE_H