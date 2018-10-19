#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsRight(char c) {
	return isdigit(c) || isalpha(c) || c == '_' || c == '-' || c == '.';
}

vector<int> Findat(string sample) {
	vector<int> Res;
	int Length = sample.length();
	for (int i = 0; i < Length; i++)
		if (sample[i] == '@')
			Res.push_back(i);
	return Res;
}

int main() {
	vector<string> Input;
	vector<string> Out;
	string Command;
	while (getline(cin,Command))
		Input.push_back(Command);
	int Size = Input.size();
	for (int i = 0; i < Size; i++) {
		vector<int> Index = Findat(Input[i]);
		int Number_at = Index.size();
		for (int j = 0; j < Number_at; j++) {
			string address;
			int Index_First = -1;
			int Index_Last = -1;
			for (int k = Index[j] - 1; k > 0; k--)
				if (!IsRight(Input[i][k])) {
					Index_First = k + 1;
					break;
				}
			for (int k = Index[j] + 1; k < Input[i].length(); k++)
				if (!IsRight(Input[i][k])) {
					Index_Last = k - 1;
					break;
				}
			if (Index_First == -1)
				Index_First = 0;
			if (Index_Last == -1)
				Index_Last = Input[i].length() - 1;
			while (Input[i][Index_First] == '.')
				Index_First++;
			while (Input[i][Index_Last] == '.')
				Index_Last--;
			for (int k = Index_First; k < Index_Last; k++) {
				if (Input[i][k] =='.'&& Input[i][k + 1] == '.') {
					if (k < Index[j]) {
						Index_First = k + 2;
						k += 2;
					}
					else {
						if (k - 1 < Index_Last)
							Index_Last = k - 1;
						break;
					}
				}
			}
			if ((Index_First < Index[j]) && (Index[j] < Index_Last))
				Out.push_back(Input[i].substr(Index_First, Index_Last - Index_First + 1));
		}
	}
	for (int i = 0; i < Out.size(); i++)
		cout << Out[i] << endl;
	return 0;
}