#include <iostream>
#include <string>

using namespace std;

int main() {
	string Input;
	while (cin >> Input) {
		int count = 0;
		int j = 0;
		for (int i = 0; i < 11; i++) {
			if (Input[i] == '-') {
				continue;
			}
			count += (Input[i] - 48)*(10-j);
			j++;
		}
		int K = 11 - (count % 11);
		Input += '-';
		if (K == 10)
			Input += 'X';
		else if (K == 11)
			Input += (char)(48);
		else
			Input += (char)(K + 48);
		cout << Input << endl;
	}
	return 0;
}