#include <iostream>
#include <string>

using namespace std;

int mini(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int LCS(string a, string b) {
	int res[1010][1010];
	int length1 = a.length();
	int length2 = b.length();
	for (int i = 0; i < length1; i++)	//b选0个，而非b下标为0
		res[i][0] = 0;
	for (int i = 0; i < length2; i++)	//a选0个，而非a下表为0
		res[0][i] = 0;
	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {	//==
			if (a[i-1] == b[j-1])		//长度为i，所以索引值为a[i-1]
				res[i][j] = res[i - 1][j - 1] + 1;
			else
				res[i][j] = max(res[i - 1][j], res[i][j - 1]);
		}
	}
	return res[length1][length2];	//legnth1 length2
}

int main() {
	string sample1;
	string sample2;
	while (cin >> sample1) {
		cin >> sample2;
		cout << LCS(sample1, sample2) << endl;
	}
	return 0;
}