/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Junhui DENG, deng@tsinghua.edu.cn
* Computer Science & Technology, Tsinghua University
* Copyright (c) 2006-2013. All rights reserved.
******************************************************************************************/

#pragma once

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> 
struct ListNode {
	T data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;
	ListNode(){}
	ListNode(T e,ListNodePosi(T) p =NULL,ListNodePosi(T) s= NULL):data(e),pred(p),succ(s){}
	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e);

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e);

template <typename T> class List { //�б�ģ����

private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer; //��ģ��ͷ�ڱ���β�ڱ�

protected:
	void init(); //�б���ʱ�ĳ�ʼ��
	int clear(); //������нڵ�
	void copyNodes(ListNodePosi(T), int); //�����б�����λ��p���n��
	void merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m); //�鲢
	void mergeSort(ListNodePosi(T)& p, int n); //�Դ�p��ʼ������n���ڵ�鲢����
	void selectionSort(ListNodePosi(T) p, int n); //�Դ�p��ʼ������n���ڵ�ѡ������
	void insertionSort(ListNodePosi(T) p, int n); //�Դ�p��ʼ������n���ڵ��������

public:
	// ���캯��
	List() { init(); } //Ĭ��
	List(List<T> const& L); //���帴���б�L
	List(List<T> const& L, Rank r, int n); //�����б�L���Ե�r�����n��
	List(ListNodePosi(T) p, int n); //�����б�����λ��p���n��
									// ��������
	~List(); //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�
			 // ֻ�����ʽӿ�
	Rank size() const { return _size; } //��ģ
	bool empty() const { return _size <= 0; } //�п�
	T& operator[] (Rank r) const; //���أ�֧��ѭ�ȷ��ʣ�Ч�ʵͣ�
	ListNodePosi(T) first() const { return header->succ; } //�׽ڵ�λ��
	ListNodePosi(T) last() const { return trailer->pred; } //ĩ�ڵ�λ��
	bool valid(ListNodePosi(T) p) //�ж�λ��p�Ƿ����Ϸ�
	{
		return p && (trailer != p) && (header != p);
	} //��ͷ��β�ڵ��ͬ��NULL
	int disordered() const; //�ж��б��Ƿ�������
	ListNodePosi(T) find(T const& e) const //�����б����
	{
		return find(e, _size, trailer);
	}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const; //�����������
	ListNodePosi(T) search(T const& e) const //�����б����
	{
		return search(e, _size, trailer);
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //�����������
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); //��p����n-1�������ѡ�������
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); } //���������
																		   // ��д���ʽӿ�
	ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ����
	ListNodePosi(T) insertAsLast(T const& e); //��e����ĩ�ڵ����
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e); //��e����p�ĺ�̲���
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e); //��e����p��ǰ������
	T remove(ListNodePosi(T) p); //ɾ���Ϸ�λ��p���Ľڵ�,���ر�ɾ���ڵ�
	void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); } //ȫ�б�鲢
	void sort(ListNodePosi(T) p, int n); //�б���������
	void sort() { sort(first(), _size); } //�б���������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
	void reverse(); //ǰ���ã�ϰ�⣩
					// ����
	void traverse(void(*) (T&)); //����������ʵʩvisit����������ָ�룬ֻ����ֲ����޸ģ�
	template <typename VST> //������
	void traverse(VST&); //����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�
}; //List


#include <iostream>
using namespace std;

template <typename T>
void insertBefore(ListNodePosi(T) p1, T data) {
	p1->insertAsPred(data);
}

template <typename T>
void insertAfter(ListNodePosi(T) p1, T data) {
	p1->insertAsSucc(data);
}


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);
	pred->succ = x;
	this->pred = x;
	return x;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi(T) x = new ListNode(e, this, succ);
	succ->pred = x;
	this->succ = x;
	return x;
}


template <typename T>
void List<T>::init() {
header = new ListNode<T>;
trailer = new ListNode<T>;
header->succ = trailer;
header->pred = NULL;
trailer->pred = header;
trailer->succ = NULL;
_size = 0;
}


template <typename T>
T& List<T>::operator[] (Rank r) const {//Rank=0-----header  Rank=_size-----trailer
	ListNodePosi(T) p = first();
	while (r-- > 0) {
		p = p->succ;
	}
	return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::find(T const &e, int n, ListNodePosi(T) p) const {
	while (n-- > 0) {
		if (e == (p = p->pred)->data) return p;
	}
	return NULL;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e) {
	_size++;
	return header->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e) {
	_size++;
	return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e) {
	_size++;
	return p->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const& e) {
	_size++;
	return p->insertAsPred(e);
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T), int n) {
	init();
	while (n--) {
		insertAsFirst(p->data);
		p = p->succ;
	}
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n) {
	copyNodes(L[r], n);
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p) {
	T e = p->data;
	p->succ->pred = p->pred;
	p->pred->succ = p->succ;
	delete p;
	_size--;
	return e;
}

template <typename T>
int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size) remove(header->succ);
	return oldSize;
}


template <typename T>
List<T>::~List() {
clear();
delete header;
delete trailer;
}


template <typename T>
int List<T>::deduplicate() {
	if (_size < 2)
		return 0;
	int oldSize = _size;
	ListNodePosi(T) p = header; Rank r = 0;
	while (trailer != (p = p->succ)) {
		ListNodePosi(T) q = find(p->data, r, p);
		q = NULL ? remove(q) : r++;
	}
	return oldSize - _size;
}

template <typename T>
void List<T>::traverse(void(*visit)(T&)) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) {
		visit(p->data);
	}
}

template <typename T>
template <typename VST>
void List<T>::traverse(VST& visit) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) {
		visit(p->data);
	}
}

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n) {
	switch ((rand() % 3) + 1) {
	case 1: cout << "InsertionSort:" << endl; insertionSort(p, n); break;
	case 2:cout << "selectionSort:" << endl; selectionSort(p, n); break;
	case 3:cout << "mergeSort:" << endl; mergeSort(p, n); break;
	}
}

template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const {	//�����б�Ĳ���
	while (n-- > 0) {
		if (((p = p->pred)->data) <= e) break;
	}
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {	//�׽ڵ�p����
	ListNodePosi(T) max = p;
	for (ListNodePosi(T) cur = p; 1 < n; n--) {
		if (!((cur = cur->succ)->data<max->data))	//��˷��ص������ұߵ�Ԫ��
			max = cur;
	}
	return max;
}


template<typename T>
inline void List<T>::selectionSort(ListNodePosi(T) p, int n)
{
	ListNodePosi(T) head = p->pred;
	ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++) tail = tail->succ;
	while (n > 1) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertBefore(tail, remove(max));
		tail = tail->pred;
		n--;
	}
}

template<typename T>
inline void List<T>::insertionSort(ListNodePosi(T) p, int n)
{
	for (int r = 0; r < n + 1; r++) {
		insertAfter(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}

template <typename T>
void List<T>::merge(ListNodePosi(T) &p, int n, List<T>& L, ListNodePosi(T) q, int m) {
	ListNodePosi(T) pp = p->pred;
	while (m > 0) {
		if (n > 0 && (p->data <= q->data)) {
			if (q == (p = p->succ)) break; n--;
		}
		else {
			insertBefore(p, L.remove((q = q->succ)->pred)); m--;
		}
	}
	p = pp->succ;
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T) &p, int n) {
	if (n < 2)
		return;
	int m = n >> 1;
	ListNodePosi(T) q = p;
	for (int i = 0; i < m; i++)
		q = q->succ;
	mergeSort(p, m); mergeSort(q, n - m);
	merge(p, m, *this, q, n - m);
}