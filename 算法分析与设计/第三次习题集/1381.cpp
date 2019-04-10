#include <iostream>
#include <string>
#include <time.h>
#pragma warning(disable:4996)

using namespace std;

string add(string a, string b) {
	int x;
	if (a.length() < b.length()) {
		string temp = a;
		a = b;
		b = temp;
	}
	string res(a);
	for (int i = b.length() - 1; i >= 0; i--) {
		res[i + res.length() - b.length()] += (b[i] - '0');
		if (res[i + res.length() - b.length()] > '9') {
			x = res[i + res.length() - b.length()] - '0';
			res[i + res.length() - b.length()] = (res[i + res.length() - b.length()] - '0') % 10 + 48;
			if (i + res.length() - b.length() != 0) {
				res[i + res.length() - b.length() - 1] += (((x)/10));
			}
			else {
				string k;
				k.push_back((char)(x / 10 + 48));
				res.insert(0, k);
			}
		}
	}

	return res;
}

string mul(string a, string b) {
	if (a.length() < b.length()) {
		string temp = a;
		a = b;
		b = temp;
	}
	string res = "0";
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < b[i] - '0'; j++) {
			res = add(res,a);
		}
		if(i!=b.length()-1)
			res.push_back('0');
	}
	for (int i = res.length() - 1; i >= 0; i--) {
		if (res[i] > '9') {
			int x = res[i] - '0';
			res[i] = (x % 10) + '0';
			if (i == 0) {
				string k;
				k.push_back((char)(x / 10 + 48));
				res.insert(0, k);
			}
			else {
				res[i - 1] += ((x / 10));
			}
		}
	}
	return res;
}

int main() {
	srand(time(NULL));
	int T;
	string a, b;
	char k[256];
	char h[256];
	string ans;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		//int e = rand() % 1000000 + 1;
		//int f = rand() % 1000000 + 1;
		//int p = e*f;
		//itoa(e,k,10);
		//itoa(f,h,10);
		//a = k;
		//b = h;
		ans = mul(a, b);
		int c = 0;
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] != '0')
				break;
			else
				c++;
		}
		ans.erase(0, c);
		if (ans == "")
			ans = "0";
		char asd[256];
		//itoa(p, asd, 10);
		//string st = asd;
		//if (st != ans)
		//	cout << "Error" << endl;
		cout << ans << endl;
	}
	return 0;
}