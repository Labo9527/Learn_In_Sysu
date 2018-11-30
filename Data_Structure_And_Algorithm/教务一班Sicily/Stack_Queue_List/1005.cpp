#include <iostream>
#include <stack>

#define MAX 1010

using namespace std;

int arr[MAX];
bool picture[MAX][MAX];
int color[MAX];
int small[MAX];
bool flag;
int N;


void set_color(int i, int c) {
	color[i] = c;
	for (int j = 0; j < N; j++) {
		if (picture[i][j]) {
			if (color[j] == c) {
				flag = false;
			}
			if (!color[j]) {
				set_color(j, 3 - c);
			}
		}
	}
}

int main() {
	while (cin >> N) {
		flag = true;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			color[i] = 0;
			small[i] = 0;
			for (int j = 0; j < N; j++)
				picture[i][j] = 0;
		}
		{
			small[N] = 0x7FFFFFFF;
			for (int i = N - 1; i >= 0; i--) {
				small[i] = arr[i];
				if (small[i + 1] < small[i])
					small[i] = small[i + 1];
			}
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					if (arr[i] < arr[j] && small[j + 1] < arr[i])
						picture[i][j] = picture[j][i] = 1;
				}
			}
			for (int i = 0; i < N; i++) {
				if (!color[i])
					set_color(i, 1);
			}
		}
		{
			if (flag == false) {
				cout << "0" << endl;
				continue;
			}
			stack<int> stack1;
			stack<int> stack2;
			int count = 0;
			int aim = 1;
			for (int i = 0; i < N; i++) {
				if (color[i] == 1) {
					stack1.push(arr[i]);
					count++;
					cout << "a";
					if (count < N * 2)
						cout << " ";
				}
				else {
					stack2.push(arr[i]);
					count++;
					cout << "c";
					if (count < N * 2)
						cout << " ";
				}
				while ((!stack1.empty() && stack1.top() == aim) ||
					(!stack2.empty() && stack2.top() == aim)) {
					if (!stack1.empty() && stack1.top() == aim) {
						stack1.pop();
						count++;
						aim++;
						cout << "b";
						if (count < N * 2)
							cout << " ";
					}
					else {
						stack2.pop();
						count++;
						aim++;
						cout << "d";
						if (count < N * 2)
							cout << " ";
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}