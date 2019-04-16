#include <iostream>
#include <string>

using namespace std;

int main() {
	string num;
	long long int res;
	while (cin >> num, num != "0") {
		cout << num << ": ";
		res = 0;
		for (int i = 0; i < num.length(); i++)
			if (num[i] >= '4')
				num[i] = num[i] - 1;
		for (int i = 0; i < num.length(); i++) {
			res *= 9;
			res += num[i] - '0';
		}
		cout << res << endl;
	}
	return 0;
}