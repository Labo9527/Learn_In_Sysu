#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int primes[1000000];

bool isPrime(int num) {
	if (num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num%i == 0)
			return false;
	return true;
}

int main() {
	int count = 0;
	for (int i = 2; i <= 1000000; i++)
		if (isPrime(i))
			primes[count++] = i;
	string k;
	int l;
	while (cin >> k >> l,!(k=="0"&&l==0)) {
		bool exist = false;
		int a = 0;
		for(int i=0;i<count;i++){
			if (primes[i] >= l)
				break;
			int num = 0;
			for (int j = 0; j < k.length(); j++) {
				num = (num * 10 + (k[j] - '0')) % primes[i];
			}
			if (num == 0) {
				exist = true;
				a = primes[i];
				break;
			}
		}
		if (exist == true)
			cout << "BAD " <<a<< endl;
		else
			cout << "GOOD" << endl;
	}
	return 0;
}