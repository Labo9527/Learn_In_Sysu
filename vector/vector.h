#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {
protected:
	Rank _size; int _capacity; T* _elem;//��ģ��������������
	void copyFrom(T const* A, Rank lo, Rank hi);//����
	void expand();//����
	void shrink();//ѹ��
	bool bubbleSort(Rank lo, Rank hi);//ð������
	Rank max(Rank lo, Rank mi, Rank hi);//ѡȡ���Ԫ��
	void selectionSort(Rank lo, Rank hi);//ѡ������
	void merge(Rank lo, Rank mi, Rank hi);//�鲢
	void mergeSort(Rank lo, Rank hi);//�鲢����
	Rank partition(Rank lo, Rank hi);//��㹹��
	void quickSort(Rank lo, Rank hi);//��������
	void heapSort(Rank lo, Rank hi);//������
};

#endif // !VECTOR_H

