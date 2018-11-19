#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool bigger(char a, char b) {
	if (a == '*' || a == '/')
		return true;
	else
		return b == '+' || b == '-';
}

int main() {
	string sample;
	while (cin >> sample) {
		int length = sample.length();
		stack<char> op;
		for (int i = 0; i < length; i++) {
			if (isalpha(sample[i]))
				cout << sample[i];
			else {
				if (op.size() == 0)
					op.push(sample[i]);
				else {
					while (op.size() != 0 && bigger(op.top(), sample[i])) {
						cout << op.top();
						op.pop();
					}
					op.push(sample[i]);
				}
			}
		}
		while (op.size() != 0) {
			cout << op.top();
			op.pop();
		}
	}
	return 0;
}