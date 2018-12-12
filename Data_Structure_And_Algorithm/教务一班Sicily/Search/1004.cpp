#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool binSearch(vector<int> s, const int size, const int target)
{
	int start = 0;
	int end = size - 1;
	bool judge = false;
	int mid = (end - start) / 2 + start;
	while (start <= end)
	{
		mid = (end - start) / 2 + start;
		if (s[mid] < target)
		{
			start = mid + 1;
		}
		else if (s[mid] == target)
		{
			judge = true;
			return 1;
			break;
		}
		else
		{
			end = mid - 1;
		}
	}
	if (judge == false)
	{
		return false;
	}
}

void quicksort(vector<int>& v, int l, int r) {
	if (l < r) {
		int i = l, j = r, x = v[i];
		while (i < j) {
			while (i<j&&v[j]>=x) j--;
			if (i < j)
				v[i++] = v[j];
			while (i < j&&v[i] < x) i++;
			if (i < j)
				v[j--] = v[i];
		}
		v[i] = x;
		quicksort(v, l, i - 1);
		quicksort(v, i + 1, r);
	}
}

bool binaryFind(vector<int> v, int target) {
	int l = 0, r = v.size() - 1;
	int m;
	while (l <= r) {
		m = (r - l) / 2 + l;
		
		if (r - l == 1) {
			if (target == v[l] || target == v[r]) return true;
			return false;
		}
		
		if (v[m] == target) return true;
		else if (v[m] < target) l = m + 1;
		else r = m - 1;
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, num;
		vector<int> v1;
		vector<int> v2;
		//map<int, int> book1;
		//map<int, int> book2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			//if (book1[num] == 0) {
			//	book1[num] = 1;
				v1.push_back(num);
			//}
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> num;
			//if (book2[num] == 0) {
			//	book2[num] = 1;
				v2.push_back(num);
			//}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		auto t1 = unique(v1.begin(), v1.end());
		auto t2 = unique(v2.begin(), v2.end());
		v1.erase(t1, v1.end());
		v2.erase(t2, v2.end());
		//quicksort(v1, 0, v1.size() - 1);
		//quicksort(v2, 0, v2.size() - 1);
		int size = v1.size();
		bool flag = false;
		bool *sad = new bool[v1.size()];
		for (int i = 0; i < size; i++) {
			sad[i] = (binSearch(v2, v2.size(), v1[i])==false) ? true : false;
		}
		for (int i = 0; i < size; i++) {
			//if (!binaryFind(v2, v1[i])) {
			if(sad[i]){
				if (flag) {
					cout << " ";
				}
				cout << v1[i];
				flag = true;
			}
		}
		cout << endl;
		delete[]sad;
	}
	return 0;
}