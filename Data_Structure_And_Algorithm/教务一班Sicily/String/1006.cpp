#include <iostream>
#include <string>

using namespace std;

int main() {
	string Sample;
	while (cin >> Sample&&Sample != "XXX") {
		string Res;
		int Length = Sample.length();
		for (int i = 0; i < Length - 1; i++) {
			if (!isdigit(Sample[i + 1]))
				Res += Sample[i];
			else {
				int k = i;
				int count = 0;
				while (i + 1 < Length&&isdigit(Sample[i + 1])) {
					count *= 10;
					count += (Sample[i+1] - 48);
					i++;
				}
				for (int j = 0; j < count; j++) {
					Res += Sample[k];
				}
			}
		}
		if (!isdigit(Sample[Length - 1]))
			Res += Sample[Length - 1];
		cout << Res << endl;
	}
	return 0;
}