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
	int n;
	int primes[10010];
	int sums[10010];
	int Pcount = 0;
	for (int i = 2; i <= 10000; i++)
		if (isPrime(i))
			primes[Pcount++] = i;
	sums[1] = primes[0];
	sums[0] = 0;
	for (int i = 2; i < Pcount; i++)
		sums[i] = sums[i - 1] + primes[i - 1];
	while (cin >> n, n) {
		int Count = 0;
		for (int i = 0; i < Pcount; i++) {
			for (int j = i; j < Pcount; j++) {
				if (sums[j] - sums[i] == n)
					Count++;
			}
		}
		cout << Count << endl;
	}
	return 0;
}