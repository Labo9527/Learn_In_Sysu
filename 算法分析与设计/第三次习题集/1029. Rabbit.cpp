#include <iostream>

using namespace std;

int main() {
	int m, d;
	int number[110][110];	//number[i][j]记录第i个月的兔子总数的第j位（逆向）
	while (cin >> m >> d, m && d) {
		memset(number, 0, sizeof(number));
		for (int i = 0; i <= m; i++)
			number[i][0] = i + 1;
		for (int i = m + 1; i <= d; i++) {
			for (int j = 0; j < 110; j++) {	//数组实现大整数加法
				number[i][j] = number[i][j] + number[i - 1][j] + number[i - m][j];	//number[i]=number[i-1]+number[i-m]
				if (number[i][j] > 9) {
					number[i][j + 1] = number[i][j + 1] + number[i][j] / 10;
					number[i][j] %= 10;
				}
			}
		}
		bool flag = false;
		for (int j = 109; j >= 0; j--) {
			if (!flag&&number[d][j] == 0)
				continue;
			else {
				flag = true;
				cout << number[d][j];
			}
		}
		cout << endl;
	}
	return 0;
}