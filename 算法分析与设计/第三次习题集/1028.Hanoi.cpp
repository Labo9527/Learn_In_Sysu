#include <iostream>
#include <string>

using namespace std;

int fun(string N) {
	int res = 0;
	int temp = 0;
	while (N[N.length() - 1] % 2 == 0) {	//ÅÐÅ¼
		string t;
		for (int i = 0; i < N.length(); i++) {	//´óÕûÊý³ý2
			int n = temp * 10 + (N[i] - '0');
			temp = n % 2;
			t += (n / 2 + '0');
		}
		N = t;
		res++;
	}
	return res + 1;
}

int main() {
	int T;
	string N;
	cin >> T;
	int count = 0;
	while (T--) {
		cin >> N;
		cout << "Case "<<++count<<": "<< fun(N) << endl;
		if (T)
			cout << endl;
	}
	return 0;
}