#include <iostream>
#include <string>

using namespace std;

int main() {
	string key;
	string encry;
	string matrix[110][110];
	char t;
	while (cin >> key, key != "THEEND") {
		int count = 0;
		cin >> encry;
		for (int i = 0; i < key.length(); i++) {
			int order = -1;
			for (int j = 0; j < key.length(); j++) {
				if (order == -1 && key[j] != '@') {
					t = key[j];
					order = j;
				}
				else if (order != -1 && t > key[j] && key[j]!='@') {
					t = key[j];
					order = j;
				}
			}
			key[order] = '@';
			for (int j = 0; j < encry.length() / key.length(); j++)
				matrix[j][order] = encry[count++];
		}
		for (int i = 0; i < encry.length() / key.length(); i++)
			for (int j = 0; j < key.length(); j++)
				cout << matrix[i][j];
		cout << endl;
	}
	return 0;
}