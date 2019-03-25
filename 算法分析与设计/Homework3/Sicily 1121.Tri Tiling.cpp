#include <iostream>

using namespace std;

int main() {
	int n;
	int s[35][2];
	s[0][0] = 1;
	s[0][1] = 0;
	s[2][0] = 3;
	s[2][1] = 2;
	for (int i = 4; i <= 30; i+=2) {
		s[i][0] = s[i - 2][0] * 3 + s[i - 2][1];
		s[i][1] = s[i - 2][0] * 2 + s[i - 2][1];
	}
	while (cin >> n && n != -1) {
		if (n % 2 == 1)
			cout << 0 << endl;
		else
			cout << s[n][0] << endl;
	}
	return 0;
}//²Î¿¼ÁËCSDN BLOG