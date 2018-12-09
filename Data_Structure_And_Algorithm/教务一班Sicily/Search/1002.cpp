#include <iostream>
#include <vector>
#include <map>

using namespace std;

void QuickSort(vector<int>& s, int l, int r) {
	if (l < r) {
		int i = l, j = r, x = s[l];
		while (i < j) {
			while (i<j&&s[j]>=x)
				j--;
			if(i<j)
				s[i++] = s[j];
			while (i < j&&s[i] < x)
				i++;
			if(i<j)
				s[j--] = s[i];
		}
		s[i] = x;
		QuickSort(s, l, i - 1);
		QuickSort(s, i + 1, r);
	}
}

int main() {
	int n;
	int num;
	bool flag = false;
	while (cin >> n&&n) {
		vector<int> book;
		map<int, int> S;
		if (flag)
			cout << endl;
		flag = true;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (!S[num]) {
				S[num] = 1;
				book.push_back(num);
			}
			else
				S[num]++;
		}
		QuickSort(book, 0, book.size() - 1);
		for (int i = 0; i< book.size(); i++)
			cout << book[i] << " " << S[book[i]] << endl;
	}
	return 0;
}