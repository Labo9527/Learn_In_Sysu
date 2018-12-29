#include <iostream>
#include <string>

using namespace std;

bool issign(string s, int i) {
	return (i == 0 || !isdigit(s[i - 1])) && (s[i] == '+' || s[i] == '-') && isdigit(s[i + 1]);
}

void norminalize(string &s) {
	//string temp;
	char temp[1000];
	int i, j;
	for (i = 0, j = 0; i < s.length(); i++, j++) {
		if (isdigit(s[i])) {
			if (i == 0 || (s[i - 1] != '+'&&s[i - 1] != '-'))
				temp[j++] = '+';
			while (s[i] == '0')
				i++;
			while (isdigit(s[i]))
				temp[j++] = s[i++];
			if (temp[j - 1] == '+' || temp[j - 1] == '-')
				j--;
		}
		temp[j] = (s[i] >= 'a'&&s[i] <= 'z' ? (s[i] - 32) : s[i]);
	}
	temp[j] = '\0';
	s = temp;
}

int cmp(string s1, string s2) {
	int len1, len2;
	norminalize(s1);
	norminalize(s2);
	for (int i = 1, j = 1; i < s1.length() && j < s2.length(); i++, j++) {
		if (isdigit(s1[i]) && isdigit(s2[j])) {
			int k = i;
			while (isdigit(s1[k]))
				k++;
			len1 = k - i;
			k = j;
			while (isdigit(s2[k]))
				k++;
			len2 = k - j;
			if (len1 != len2)
				return (len1 < len2 ? -1 : 1);
			else {
				while (i < k&&j < k) {
					if (s1[i++] != s2[j++])
						return (s1[i] < s2[j] ? -1 : 1);
				}
			}
		}
		if (s1[i] != s2[j]) {
			if (issign(s1, i) && issign(s2, j))
				return (s1[i] == '-' ? -1 : 1);
			return (s1[i] < s2[j] ? -1 : 1);
		}
	}
	return 0;
}

int main() {
	int n;
	string s1, s2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		cout << i << " " << cmp(s1, s2) << endl;
	}
	return 0;
}