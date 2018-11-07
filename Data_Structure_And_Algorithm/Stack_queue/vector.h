/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Junhui DENG, deng@tsinghua.edu.cn
* Computer Science & Technology, Tsinghua University
* Copyright (c) 2006-2013. All rights reserved.
******************************************************************************************/

#pragma once

typedef int Rank; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

template <typename T> class Vector { //����ģ����
protected:
	Rank _size; int _capacity;  T* _elem; //��ģ��������������
	void copyFrom(T const* A, Rank lo, Rank hi); //������������A[lo, hi)
	void expand(); //�ռ䲻��ʱ����
	void shrink(); //װ�����ӹ�Сʱѹ��
	bool bubble(Rank lo, Rank hi); //ɨ�轻��
	void bubbleSort(Rank lo, Rank hi); //���������㷨
	Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ��
	void selectionSort(Rank lo, Rank hi); //ѡ�������㷨
	void merge(Rank lo, Rank mi, Rank hi); //�鲢�㷨
	void mergeSort(Rank lo, Rank hi); //�鲢�����㷨
	Rank partition(Rank lo, Rank hi); //��㹹���㷨
	void quickSort(Rank lo, Rank hi); //���������㷨
	void heapSort(Rank lo, Rank hi); //�������Ժ�����ȫ�ѽ��⣩
public:
	// ���캯��
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
	{
		_elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v);//��Ҫд��ת�����캯��
	} //s<=c
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //�������帴��
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //����
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); } //�������帴��
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //����
																				// ��������
	~Vector() { delete[] _elem; } //�ͷ��ڲ��ռ�
								  // ֻ�����ʽӿ�
	Rank size() const { return _size; } //��ģ
	bool empty() const { return !_size; } //�п�
	int disordered() const; //�ж������Ƿ�������
	Rank find(T const& e) const { return find(e, 0, _size); } //���������������
	Rank find(T const& e, Rank lo, Rank hi) const; //���������������
	Rank search(T const& e) const //���������������
	{
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	Rank search(T const& e, Rank lo, Rank hi) const; //���������������
													 // ��д���ʽӿ�
	T& operator[] (Rank r) const; //�����±������������������������ʽ���ø�Ԫ��
	Vector<T> & operator= (Vector<T> const&); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
	T remove(Rank r); //ɾ����Ϊr��Ԫ��
	int remove(Rank lo, Rank hi); //ɾ����������[lo, hi)֮�ڵ�Ԫ��
	Rank insert(Rank r, T const& e); //����Ԫ��
	Rank insert(T const& e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
	void sort(Rank lo, Rank hi); //��[lo, hi)����
	void sort() { sort(0, _size); } //��������
	void unsort(Rank lo, Rank hi); //��[lo, hi)����
	void unsort() { unsort(0, _size); } //��������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
					// ����
	void traverse(void(*) (T&)); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
	template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�
}; //Vector


class Fib { //Fibonacci������
private:
	int f, g; //f = fib(k - 1), g = fib(k)����Ϊint�ͣ��ܿ�ͻ���ֵ���
public:
	Fib(int n) //��ʼ��Ϊ��С��n����СFibonacci��
	{
		f = 0; g = 1; while (g < n) next();
	} //fib(-1), fib(0)��O(log_phi(n))ʱ��
	int get() { return g; } //��ȡ��ǰFibonacci�O(1)ʱ��
	int next() { g += f; f = g - f; return g; } //ת����һFibonacci�O(1)ʱ��
	int prev() { f = g - f; g -= f; return g; } //ת����һFibonacci�O(1)ʱ��
};


template <typename T>
void swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T>	//������
void permute(Vector<T>& V) {
	for (int i = V.size(); i > 0; i--) {
		swap(V[i - 1], V[rand() % i]);
	}
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {//	[lo,hi)
	T* V = _elem + lo;
	for (Rank i = hi - lo, i > 0, i--)
		swap(V[i - 1], V[rand() % i]);
}
/*
template <typename T>
void Vector<T>::unsort() {
for (Rank i = _size; i > 0; i--)
swap(_elem[i - 1], _elem[rand() % i]);
}
*/
template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {	//[lo,hi),ֻ�й��캯���ڵ�����
	_elem = new T[_capacity = 2 * (hi - lo)]; _size = 0;
	while (lo < hi) {
		_elem[_size++] = A[lo++];
	}
}

template <typename T>
void Vector<T>::expand() {
	if (_size < _capacity)
		return;
	_capacity = max(_capacity, DEFAULT_CAPACITY);//�������������
	T* oldeElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldeElem[i];
	delete[]oldeElem;
}

template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& V) {
	if (_elem) delete[]_elem;
	copyFrom(V._elem, 0, V._size);
	return *this;
}

template <typename T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return;
	if (_size << 2 > _capacity) return;
	T *oldElem = _elem; _elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[]oldElem;
}

template <typename T>
T& Vector<T>::operator[] (Rank r) const {
	return _elem[r];
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
	_elem[r] = e; _size++;
	return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi)
		return 0;
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template <typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i);
	}
	return olSize - _size;
}


template <typename T>
void Vector<T>::traverse(void(*) (T&)) {
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit) {
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

template <typename T>
int Vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; i++)
		if (_elem[i - 1] > _elem[i])
			n++;
	return n;
}

template <typename T>
int Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size) {
		if (_elem[i] != _elem[j]) {
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;
	shrink();
	return j - i;
}

template <typename T>
Rank binSearch(T* _elem, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		if (e < _elem[mi]) hi = mi;
		else if (e > _elem[mi]) lo = mi + 1;
		else return mi;
	}
	return -1;
}

template <typename T>
Rank fibSearch(T* _elem, T const& e, Rank lo, Rank hi) {
	Fib fib(hi - lo);
	while (lo < hi) {
		while (hi - lo < fib.get()) fib.prev();
		Rank mi = lo + fib.get() - 1;
		if (e < _elem[mi]) hi = mi;
		else if (e > _elem[mi]) hi = mi + 1;
		else return mi;
	}
	return -1;
}

template <typename T>
Rank binSearch_c(T const &e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;
}

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
	binSearch_c(e, lo, hi);
	/*
	srand(time(NULL));
	return (rand() % 2) ? binSearch(e, lo, hi) : fibSearch(e, lo, hi);
	*/
}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi) {
		if (_elem[lo - 1] < _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (!bubble(lo, hi));
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	int lb = mi - lo;
	T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi;
	T *C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc)) {
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] <= B[j]))) A[i++] = C[k++];
	}
	delete[]B;
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;
	int mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
	srand(time(NULL));
	siwtch(rand() % 5) {
		case 1:bubbleSort(lo, hi); break;
			//case 2:selectionSort(lo,hi); break;
		case 3:mergeSort(lo, hi); break;
			//case 4:heapSort(lo,hi); break;
		default:bubbleSort(lo, hi); break;
	}
}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {
	T max = lo;
	if (lo == hi)
		return lo;
	for (Rank i = lo; i < hi; i++)
		if (_elem[max] < _elem[i])
			max = i;
	return max;
}
/*
template <typename T>
void swap(T &a, T &b) {
T temp = a;
a = b;
b = temp;
}
*/