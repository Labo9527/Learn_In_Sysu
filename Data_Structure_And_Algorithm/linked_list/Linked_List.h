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

template <typename T> class List { //列表模板类

private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer; //规模、头哨兵、尾哨兵

protected:
	void init(); //列表创建时的初始化
	int clear(); //清除所有节点
	void copyNodes(ListNodePosi(T), int); //复制列表中自位置p起的n项
	void merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m); //归并
	void mergeSort(ListNodePosi(T)& p, int n); //对从p开始连续的n个节点归并排序
	void selectionSort(ListNodePosi(T) p, int n); //对从p开始连续的n个节点选择排序
	void insertionSort(ListNodePosi(T) p, int n); //对从p开始连续的n个节点插入排序

public:
	// 构造函数
	List() { init(); } //默认
	List(List<T> const& L); //整体复制列表L
	List(List<T> const& L, Rank r, int n); //复制列表L中自第r项起的n项
	List(ListNodePosi(T) p, int n); //复制列表中自位置p起的n项
									// 析构函数
	~List(); //释放（包含头、尾哨兵在内的）所有节点
			 // 只读访问接口
	Rank size() const { return _size; } //规模
	bool empty() const { return _size <= 0; } //判空
	T& operator[] (Rank r) const; //重载，支持循秩访问（效率低）
	ListNodePosi(T) first() const { return header->succ; } //首节点位置
	ListNodePosi(T) last() const { return trailer->pred; } //末节点位置
	bool valid(ListNodePosi(T) p) //判断位置p是否对外合法
	{
		return p && (trailer != p) && (header != p);
	} //将头、尾节点等同于NULL
	int disordered() const; //判断列表是否已排序
	ListNodePosi(T) find(T const& e) const //无序列表查找
	{
		return find(e, _size, trailer);
	}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const; //无序区间查找
	ListNodePosi(T) search(T const& e) const //有序列表查找
	{
		return search(e, _size, trailer);
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //有序区间查找
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); //在p及其n-1个后继中选出最大者
	ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); } //整体最大者
																		   // 可写访问接口
	ListNodePosi(T) insertAsFirst(T const& e); //将e当作首节点插入
	ListNodePosi(T) insertAsLast(T const& e); //将e当作末节点插入
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e); //将e当作p的后继插入
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e); //将e当作p的前驱插入
	T remove(ListNodePosi(T) p); //删除合法位置p处的节点,返回被删除节点
	void merge(List<T>& L) { merge(first(), size, L, L.first(), L._size); } //全列表归并
	void sort(ListNodePosi(T) p, int n); //列表区间排序
	void sort() { sort(first(), _size); } //列表整体排序
	int deduplicate(); //无序去重
	int uniquify(); //有序去重
	void reverse(); //前后倒置（习题）
					// 遍历
	void traverse(void(*) (T&)); //遍历，依次实施visit操作（函数指针，只读或局部性修改）
	template <typename VST> //操作器
	void traverse(VST&); //遍历，依次实施visit操作（函数对象，可全局性修改）
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
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const {	//有序列表的查找
	while (n-- > 0) {
		if (((p = p->pred)->data) <= e) break;
	}
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {	//首节点p参与
	ListNodePosi(T) max = p;
	for (ListNodePosi(T) cur = p; 1 < n; n--) {
		if (!((cur = cur->succ)->data<max->data))	//因此返回的是最右边的元素
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