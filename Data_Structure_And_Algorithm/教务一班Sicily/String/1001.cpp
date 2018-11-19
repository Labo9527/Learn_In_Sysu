#include <iostream>
#include <string>

using namespace std;

string rev(string sample) {
	string res;
	int length = sample.length();
	for (int i = length - 1; i>=0; i --)
		res += sample[i];
	return res;
}

string process(string sample) {
	if (sample.length() == 0)
		return "";
	bool exit = true;
	for (int i = 0; i < sample.length(); i++)
		if (sample[i] != ' ')
			exit = false;
	if (exit)
		return "";
	int length = sample.length();
	string substr1;
	string substr2;
	if (length % 2 == 0) {
		substr1 = sample.substr(0, length / 2);
		substr2 = sample.substr(length / 2, length / 2);
	}
	else {
		substr1 = sample.substr(0, length / 2+1);
		substr2 = sample.substr(length / 2+1, length / 2);
	}
	cout << rev(substr1);
	cout << rev(substr2);
	cout << endl;
	return "";
}

int main() {
	string str1;
	string str2;
	while (getline(cin,str1)&&getline(cin,str2)) {
		process(str2);
		process(str1);
	}
	return 0;
}