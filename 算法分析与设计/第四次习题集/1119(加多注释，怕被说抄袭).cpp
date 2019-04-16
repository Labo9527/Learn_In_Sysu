#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int year;
	while (cin >> year, year) {
		double sum = 0;
		double bit = pow(2, (year-1960)/10 + 2);//借鉴了CSDN的写法这里
		int n = 2;
		while (true) {
			sum = sum + log(n) / log(2);
			if (sum > bit)
				break;
			n++;
		}
		cout << n - 1 << endl;
	}
	return 0;
}