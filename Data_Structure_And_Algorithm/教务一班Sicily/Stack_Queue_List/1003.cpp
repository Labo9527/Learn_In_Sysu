#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
	int T;
	string sample;
	cin >> T;
	while (T--) {
		cin >> sample;
		stack<double> num;
		stack<char> ope;
		int length = sample.length();
		for (int i = 0; i < length; i++) {
			if (isalpha(sample[i])) {
				num.push(sample[i] - 'a' + 1);
			}
			else {
				if (sample[i] == '+') {
					double num1 = num.top();
					num.pop();
					double num2 = num.top();
					num.pop();
					num.push(num1 + num2);
				}
				else if (sample[i] == '-') {
					double num1 = num.top();
					num.pop();
					double num2 = num.top();
					num.pop();
					num.push(num2 - num1);
				}
				else if (sample[i] == '*') {
					double num1 = num.top();
					num.pop();
					double num2 = num.top();
					num.pop();
					num.push(num1 * num2);
				}
				else if (sample[i] == '/') {
					double num1 = num.top();
					num.pop();
					double num2 = num.top();
					num.pop();
					num.push(num2 / num1);
				}
			}
		}
		cout << setprecision(2)<< fixed  << num.top() << endl;
	}
	return 0;
}