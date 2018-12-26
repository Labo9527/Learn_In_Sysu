#include <iostream>
#include <cstdio>

using namespace std;


template <typename T>
class Queue {
public:
	T data[100];
	int fro;
	int rear;
	int count;
	Queue() {
		fro = 0;
		count = 0;
		rear = 0;
	}   // construct an empty queue
	~Queue() {

	}  // destructor
	Queue(const Queue &rhs) {
		for (int i = 0; i < 100; i++)
			data[i] = rhs.data[i];
		fro = rhs.fro;
		rear = rhs.rear;
		count = rhs.count;
	}
	/*
	const Queue & operator = (const Queue &rhs) {
		count = rhs.size();
		int temp[100];
		for (int i = 0; i < count; i++) {
			temp[i] = rhs.front();
			rhs.pop();
		}

		for (int i = 0; i < count; i++) {
			push(temp[i]);
			rhs.push(temp[i]);
		}
	}
	*/
	bool empty()const {
		return count == 0;
	}
	/*
	bool full()const {
		return count == 100;
	}
	*/
	int size()const {
		return count;
	}
	bool push(const T &x) {
		if (count==100)
			return false;
		data[rear] = x;
		rear = (rear + 1) % 100;
		count++;
		return true;
	}//enqueue
	bool pop() {
		if (count == 0)
			return false;
		fro = (fro + 1) % 100;
		count--;
		return true;
	}//dequeue
	const T & front()const {
		return data[fro];
	}//returns a reference to the front element

private:
	//using a static array of size 100.   
};

int main() {
	Queue<int> T;
	for (int i = 0; i < 200; i++)
		T.push(i);
	for (int i = 0; i < 30; i++)
		T.pop();
	for (int i = 0; i < 5; i++)
		T.push(i);
	for (int i = 0; i < 200; i++) {
		cout << T.front() << endl;
		T.pop();
	}
	return 0;
}