#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct node {
	int a;
	int b;
	node(int c = 0, int d = 0) :a(c), b(d) {};
};

int n;
string book[110];

int distance(string nums) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		int pos[5];
		for (int j = 0; j < book[i].length(); j++)
			pos[book[i][j] - 'A'] = j;
		for (int j = 0; j < book[i].length(); j++) {
			for (int k = j + 1; k < book[i].length(); k++) {
				if (pos[nums[j] - 'A'] > pos[nums[k] - 'A']) res++;
			}
		}
	}
	return res;
}

int main() {
	string res, output;
	while (cin >> n, n) {
		res = "ABCDE";
		int min = 1000000;
		for (int i = 0; i < n; i++)
			cin >> book[i];
		do {
			int sum = 0;
			sum = distance(res);
			if (sum < min) {
				output = res;
				min = sum;
			}
		}while(next_permutation(res.begin(),res.end()));
		cout << output;
		cout << " is the median ranking with value " << min << "." << endl;
	}
	return 0;
}