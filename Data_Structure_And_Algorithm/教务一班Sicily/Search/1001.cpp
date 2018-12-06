#include <iostream>

using namespace std;

int binSearch(const int s[], const int size, const int target){
	int l = 0;
	int r = size - 1;
	int m;
	while (r > l) {
		m = (l + r) / 2;
		if (r - l == 1) {
			if (s[r] == target)
				return r;
			if (s[l] == target)
				return l;
			return -1;
		}
		if (s[m] > target)
			r = m-1;
		else
			l = m;
	}
	if (s[l] == target)
		return l;
	return -1;
}

int main() {
	int s[8] = { 0,1,1,3,3,3,6,6 };

	cout << binSearch(s, 8, 3) << endl;  //输出5

	cout << binSearch(s, 8, 1) << endl;  //输出-1

	return 0;
}