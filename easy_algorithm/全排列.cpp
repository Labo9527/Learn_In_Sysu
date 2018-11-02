#include <iostream>

using namespace std;

int number = 0;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void dfs(int cur, int Num,int *out) {
	if (cur == Num) {
		for (int i = 0; i < Num; i++)
			cout << out[i] << " ";
		cout << endl;
		number++;
		return;
	}
	for (int i = cur; i < Num; i++) {
		swap(out[cur], out[i]);
		dfs(cur + 1, Num, out);
		swap(out[cur], out[i]);
	}
}

int main() {
	int Array[] = { 1,2,3,4 };
	dfs(0, 4, Array);
	return 0;
}