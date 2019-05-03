#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

int des[2][4];

struct st {
	int steps;
	string opts;
	int board[2][4];
	st(int a = 0, string b = "") :steps(a), opts(b) {
		
	};
	/*
	st(const st& b) {
		steps = b.steps;
		opts = b.opts;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 4; j++)
				board[i][j] = b.board[i][j];
	}
	*/
};

st doa(st a) {
	int t;
	st res;
	res.opts = a.opts + "A";
	res.steps = a.steps + 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			res.board[i][j] = a.board[i][j];
	for (int i = 0; i < 2; i++) {
		int t = res.board[i][0];
		res.board[i][0] = res.board[i][2];
		res.board[i][2] = t;

		t = res.board[i][1];
		res.board[i][1] = res.board[i][3];
		res.board[i][3] = t;
	}
	return res;
}

st dob(st a) {
	int t;
	st res;
	res.opts = a.opts + "B";
	res.steps = a.steps + 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			res.board[i][j] = a.board[i][j];
	for (int i = 0; i < 2; i++) {
		t = res.board[i][0];
		for (int j = 0; j < 3; j++) {
			res.board[i][j] = res.board[i][j+1];
		}
		res.board[i][3] = t;
	}
	return res;
}

bool operator < (const st& a, const st&b) {
	return a.steps < b.steps;
}

st doc(st a) {
	int t;
	st res;
	res.opts = a.opts + "C";
	res.steps = a.steps + 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			res.board[i][j] = a.board[i][j];
	t = res.board[0][1];
	res.board[0][1] = res.board[0][2];
	res.board[0][2] = res.board[1][2];
	res.board[1][2] = res.board[1][1];
	res.board[1][1] = t;
	return res;
}

bool equal(st a) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			if (a.board[i][j] != des[i][j])
				return false;
	return true;
}

int convert(st a) {
	int res = 0;
	for(int i=0;i<2;i++)
		for (int j = 0; j < 4; j++) {
			res *= 10;
			res += a.board[i][j];
		}
	return res;
}

int main() {
	int m;
	while (cin >> m, m != -1) {
		st ini(0);
		for (int i = 0; i < 1; i++)
			for (int j = 0; j < 4; j++)
				ini.board[i][j] = i * 4 + j + 1;
		for (int j = 0; j < 4; j++)
			ini.board[1][j] = 4 + j + 1;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 4; j++)
				cin >> des[i][j];
		queue<st> book;
		set<st> book2;
		map<int, int> book3;
		book.push(ini);
		while (!book.empty()) {
			st a = book.front();
			book.pop();
			if (a.steps > m) {
				cout << -1 << endl;
				break;
			}
			if (equal(a)) {
				cout << a.steps << " " << a.opts << endl;
				break;
			}
			/*
			if (book2.count(a))
				continue;
			*/
			if (book3[convert(a)])
				continue;
			book3[convert(a)] = 1;
			book2.insert(a);
			book.push(doa(a));
			book.push(dob(a));
			book.push(doc(a));
		}
	}
	return 0;
}