#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {
protected:
	Rank _size; int _capacity; T* _elem;//规模，容量，数据区
	void copyFrom(T const* A, Rank lo, Rank hi);//复制
	void expand();//扩容
	void shrink();//压缩
	bool bubbleSort(Rank lo, Rank hi);//冒泡排序
	Rank max(Rank lo, Rank mi, Rank hi);//选取最大元素
	void selectionSort(Rank lo, Rank hi);//选择排序
	void merge(Rank lo, Rank mi, Rank hi);//归并
	void mergeSort(Rank lo, Rank hi);//归并排序
	Rank partition(Rank lo, Rank hi);//轴点构造
	void quickSort(Rank lo, Rank hi);//快速排序
	void heapSort(Rank lo, Rank hi);//堆排序
};

#endif // !VECTOR_H

