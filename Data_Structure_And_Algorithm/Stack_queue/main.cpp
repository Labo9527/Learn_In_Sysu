#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
	Queue<int> A;
	A.enqueue(3);
	A.front();
	return 0;
}