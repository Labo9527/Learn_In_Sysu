#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isleft(char a) {
	return a == '(' || a == '{' || a == '[';
}

bool isright(char a) {
	return a == ')' || a == '}' || a == ']';
}

bool match(char a, char b) {
	if (a == '(')
		return b == ')';
	if (a == '{')
		return b == '}';
	if (a == '[')
		return b == ']';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		stack<char> book;
		string sample;
		bool invalid = true;
		cin >> sample;
		for (int i = 0; i < sample.length(); i++) {
			if (isleft(sample[i]))
				book.push(sample[i]);
			else if (isright(sample[i])) {
				if (book.size() == 0||!match(book.top(),sample[i])) {
					invalid = false;
					break;
				}
				book.pop();
			}
		}
		if (book.size() != 0)
			invalid = false;
		if (invalid)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}