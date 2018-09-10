#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {
protected:
	Rank _size; int _capacity; T* _elem;
	void copyFrom(T const* A, Rank lo, Rank hi);
	void expand();
	void shrink();
	bool bubbleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank mi, Rank hi);
	void selectionSort(Rank lo, Rank hi);
};

#endif // !VECTOR_H

