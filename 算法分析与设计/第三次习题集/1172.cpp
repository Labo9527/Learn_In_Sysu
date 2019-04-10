#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 2,-2,1,-1,2,-2,1,-1 };
int dy[] = { 1,-1,2,-2,-1,1,-2,2 };

int dx1[] = { 1,-1,1,-1,0,0,1,-1 };
int dy1[] = { 1,-1,-1,1,1,-1,0,0 };

int r, c;

bool valid(int x, int y) {
	return x > 0 && y > 0 && x <= r&&y <= c;
}

struct point{
	int x;
	int y;
	point() {};
	point(int a, int b) :x(a), y(b) {};
};

bool board1[1010][1010];
bool board2[1010][1010];

int main() {
	int a, b;
	int T = 0;
	while (cin >> r >> c, r) {
		int count = 0;
		memset(board1, false, sizeof(board1));
		memset(board2, false, sizeof(board2));
		vector<point> queens;
		vector<point> knights;
		vector<point> pawns;
		for (int i = 0; i < 3; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				cin >> a >> b;
				if (i == 0) {
					queens.push_back(point(a, b));
					board1[a][b] = true;
					board2[a][b] = true;
				}
				else if (i == 1) {
					knights.push_back(point(a, b));
					board1[a][b] = true;
					board2[a][b] = true;
				}
				else {
					pawns.push_back(point(a, b));
					board1[a][b] = true;
					board2[a][b] = true;
				}
			}
		}
		for (int i = 0; i < knights.size(); i++) {
			for (int j = 0; j < 8; j++) {
				int rr = knights[i].x + dx[j];
				int cc = knights[i].y + dy[j];
				if (valid(rr, cc)) {
					board2[rr][cc] = true;
				}
			}
		}

		for (int i = 0; i < queens.size(); i++) {
			for (int j = 0; j < 8; j++) {
				int x = queens[i].x;
				int y = queens[i].y;
				while (1) {
					x = x + dx1[j];
					y = y + dy1[j];
					if (!valid(x, y)||board1[x][y])
						break;
					board2[x][y] = true;
				}
			}
		}
		count = 0;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++)
				if (!board2[i][j])
					count++;
		}
		cout << "Board " << ++T << " has " << count << " safe squares." << endl;
	}
	return 0;
}