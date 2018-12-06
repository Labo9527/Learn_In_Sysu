#include <iostream>
#include <vector>
#include <string>

using namespace std;
//哈弗曼树  https://blog.csdn.net/move_now/article/details/53398753
struct node
{
	string s;
	int weight;
	node() {};
	node(string s1, int weight1) :s(s1), weight(weight1) {};
};

vector<node> book;
vector<node>::iterator it;
int frency[26];
string code[26];

void encode(string s, int n) {
	for (it = book.begin(); it != book.end(); it++) {
		if (n >= it->weight)
			break;
	}
	book.insert(it, node(s, n));
}

int main() {
	int n;
	string Ans;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		Ans += c;
		frency[c - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (frency[i] != 0) {
			char te = 'A' + i;
			string s;
			s.push_back(te);
			encode(s, frency[i]);
		}
	}
	while (book.size() > 1) {
		int weight;
		string left = book.back().s;
		weight = book.back().weight;
		for (int i = 0; i < left.length(); i++)
			code[left[i] - 'A'] = "0" + code[left[i] - 'A'];
		book.pop_back();

		string right = book.back().s;
		weight += book.back().weight;
		for (int i = 0; i < right.length(); i++)
			code[right[i] - 'A'] = "1" + code[right[i] - 'A'];
		book.pop_back();
		encode(left + right, weight);
	}

	int Res=0;

	for (int i = 0; i < Ans.length(); i++) {
		Res += code[Ans[i] - 'A'].length();
	}

	cout << Res << endl;

	return 0;
}