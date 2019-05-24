#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() {
	int length;
	while (cin >> length) {
		int p1[110];
		int p2[110];
		int s1[110];
		int s2[110];
		int start;
		int end;
		for (int i = 0; i < length; i++)
			cin >> p1[i];
		for (int i = 0; i < length; i++)
			cin >> p2[i];
		cin >> start >> end;
		int exist[110];
		memset(exist, 0, sizeof(exist));
		for (int i = start; i <= end; i++) {
			exist[p1[i]] = 1;
			s1[i] = p1[i];
		}
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (exist[p2[i]] == 0) {
				while (count >= start&&count <= end)
					count++;
				s1[count++] = p2[i];
			}
		}

		memset(exist, 0, sizeof(exist));
		for (int i = start; i <= end; i++) {
			exist[p2[i]] = 1;
			s2[i] = p2[i];
		}
		count = 0;
		for (int i = 0; i < length; i++) {
			if (exist[p1[i]] == 0) {
				while (count >= start&&count <= end)
					count++;
				s2[count++] = p1[i];
			}
		}

		for (int i = 0; i < length; i++)
			cout << s1[i] <<((i + 1 == length) ? '\n' : ' ');
		for (int i = 0; i < length; i++)
			cout << s2[i] << ((i + 1 == length) ? '\n' : ' ');
	}
	return 0;
}