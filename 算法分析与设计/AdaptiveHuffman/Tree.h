#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class tree {
public:
	tree() {
		root = new Node();
		root->setData('N');
		root->setFrequency(0);
	}
	void insert(unsigned char t) {
		Node *NYT = findNYT();
		Node *l = new Node();
		l->setFrequency(0);
		Node *r = new Node(t, 1);
		NYT->setFrequency(1);
		NYT->setLeft(l);
		NYT->setRight(r);
	}
	void correct_frequency(Node *t) {
		int a = 0, b = 0;
		if (t->getLeft() != NULL) {
			correct_frequency(t->getLeft());
			a = t->getLeft()->getFrequency();
		}
		if (t->getRight() != NULL) {
			correct_frequency(t->getRight());
			b = t->getRight()->getFrequency();
		}
		if(a!=0||b!=0)
			t->setFrequency(a + b);
	}
	Node *FindString(Node *r,string s) {
		if (s.length() == 0 && r->getLeft() == NULL&&r->getRight() == NULL)
			return r;
		if (s.length() == 0)
			return NULL;
		if (s[0] == '0')
			return r->getLeft()==NULL?NULL:FindString(r->getLeft(), s.substr(1, s.length() - 1));
		if (s[0] == '1')
			return r->getRight()==NULL?NULL:FindString(r->getRight(), s.substr(1, s.length() - 1));
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
	void update() {
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

			for (int i = v.size()-1; i >=0 ; i--) {
				for (int j = v.size() - 1 ; j > i; j--) {
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
	bool find_code(unsigned char t,Node *r,string &s) {
		if (r->getData() == t && r->getFrequency()!=0 && r->getLeft() == NULL && r->getLeft() == NULL)
			return true;
		if (r->getLeft()!=NULL&&find_code(t, r->getLeft(), s)) {
			s = '0' + s ;
			return true;
		}
		if (r->getRight()!=NULL&&find_code(t, r->getRight(), s)) {
			s = '1' + s;
			return true;
		}
		return false;
	}
	bool find_NYT_Code(Node *r, string &s) {
		if (r->getFrequency() == 0 && r->getLeft() == NULL && r->getLeft() == NULL)
			return true;
		if (r->getLeft()!=NULL&&find_NYT_Code(r->getLeft(), s)) {
			s = '0' + s;
			return true;
		}
		if (r->getRight()!=NULL&&find_NYT_Code(r->getRight(), s)) {
			s = '1' + s;
			return true;
		}
		return false;
	}
	Node *findNYT() {
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *t = q.front();
			q.pop();
			if (t->getFrequency()==0 && t->getLeft() == NULL &&t->getRight() == NULL)
				return t;
			if (t->getLeft() != NULL)
				q.push(t->getLeft());
			if (t->getRight() != NULL)
				q.push(t->getRight());
		}
	}
	bool find(unsigned char a) {
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
	Node *get(unsigned char a) {
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
