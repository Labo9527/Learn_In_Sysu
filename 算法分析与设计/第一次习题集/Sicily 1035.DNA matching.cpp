#include <iostream>
#include <string>
#include <set>

using namespace std;

string MatchStr(string sample) {
	string res;
	for (int i = 0; i < sample.size(); i++) {
		if (sample[i] == 'A') {
			res += 'T';
		}
		else if (sample[i] == 'G') {
			res += 'C';
		}
		else if (sample[i] == 'C') {
			res += 'G';
		}
		else if (sample[i] == 'T') {
			res += 'A';
		}
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		int count = 0;
		string dna;
		multiset<string> dnas;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dna;
			string k = MatchStr(dna);
			if (dnas.count(k)) {
				count++;
				dnas.erase(dnas.lower_bound(k));
			}
			else {
				dnas.insert(dna);
			}
		}
		cout << count << endl;
	}
	return 0;
}