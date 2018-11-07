#include <iostream>
#include <string>

using namespace std;

bool islegal(char a) {
	return isalpha(a) || isalnum(a) || a == '-' || a == '_';
}

int main() {
	string sample;
	while (getline(cin, sample)) {
		for (int i = 0; i < sample.length(); i++) {
			if (sample[i] == '@') {
				int pre = i, aft = i;
				for (pre = i - 1; pre >= 0; ) {
					if (islegal(sample[pre])) {
						pre--;
					}
					else if (sample[pre] == '.'&&pre>0&&islegal(sample[pre-1])){
						pre--;
					}
					else
						break;
				}
				pre++;
				for (aft = i + 1; aft < sample.length(); ) {
					if (islegal(sample[aft])) {
						aft++;
					}
					else if (sample[aft] == '.'&&aft>0&&islegal(sample[aft+1])) {
						aft++;
					}
					else
						break;
				}
				aft--;
				if (pre < i && i < aft) {
					for (int i = pre; i <= aft; i++)
						cout << sample[i];
					cout << endl;
				}
			}
		}
	}
	return 0;
}