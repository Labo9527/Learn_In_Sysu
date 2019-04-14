#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int a) {
	if (a == 1)
		return false;
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0)
			return false;
	return true;
}

int main() {
	int k;
	while (cin >> k, k) {
		if (isPrime(k))
			cout << 0 << endl;
		else {
			int a = k - 1;
			int b = k + 1;
			while (!isPrime(a))
				a--;
			while (!isPrime(b))
				b++;
			cout << b - a << endl;
		}
	}
	return 0;
}