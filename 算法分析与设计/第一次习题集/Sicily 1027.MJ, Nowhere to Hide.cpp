#include iostream
#include string
#include cstdio
#include string.h
#include algorithm
#include vector
#include map

using namespace std;

struct node1 {
	string ip;
	string id;
};

struct node {
	string first;
	string second;
};

bool cmp(node a, node b) {
	return a.first  b.first;
}

int main() {
	int n;
	while (cin  n && n) {
		mapstring, string book;
		mapstring, int exist;
		vectornode pump;
		vectornode1 st;
		for (int i = 0; i  n; i++) {
			string ID, IP;
			cin  ID  IP;
			node1 t;
			t.id = ID;
			t.ip = IP;
			st.push_back(t);
		}
		for (int i = 0; i  n - 1; i++) {
			for (int j = i + 1; j  n; j++) {
				if (st[i].ip == st[j].ip) {
					node t;
					t.first = st[i].id;
					t.second = st[j].id;
					pump.push_back(t);
				}
			}
		}
		sort(pump.begin(), pump.end(), cmp);
		for (int i = 0; i  pump.size(); i++)
			cout  pump[i].second   is the MaJia of   pump[i].first  endl;
		cout  endl;
	}
	return 0;
}