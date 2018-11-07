#include <iostream>

using namespace std;

typedef int Stack_entry;

class Stack {
public:
	// Standard Stack methods
	Stack() {
		pos = 0;
	}
	bool empty() const {
		return pos == 0;
	}
	/* Returns true if the stack is empty, otherwise, returns false.
	*/
	int size() const {
		return pos;
	}
	/* Returns the number of elements in the stack.
	*/
	void push(const Stack_entry &item) {
		data[pos++] = item;
	}
	/*item is pushed into the stack and it becomes the new top element.
	*/
	void pop() {
		if (pos == 0)
			return;
		pos--;
	}
	/*The top item is removed if the stack is not empty.
	Otherwise, nothing happens.
	*/

	Stack_entry  top() const {
		if (pos == 0)
			return -1;
		return data[pos - 1];
	}
	/* The top element is returned by item if the stack is not empty,
	and the stack remains unchanged.
	Nothing happens if the stack is empty.
	*/
	// Safety features
	~Stack() {

	}
	Stack(const Stack &original) {
		*this = original;
	}
	void operator =(const Stack &original) {
		for (int i = 0; i < original.pos; i++) {
			data[i] = original.data[i];
		}
		pos = original.pos;
	}
	Stack_entry data[10000];
	int pos;
};


typedef Stack MyStack;

//or if your are using templates

int main() {

}