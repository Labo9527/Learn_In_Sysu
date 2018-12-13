#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

struct  ALGraph {

	vector<list<int> > adj; //adjacency list of the graph

	int vexnum;// number of vertices

	int arcnum;//number of edges

			   //A  simple initialization.

	ALGraph(int n = 0) :vexnum(n) {
		list<int> l;
		adj.resize(n, l);
	}

};

vector<pair<int, int> > degree(const ALGraph &g) {
	vector<pair<int, int>> res;
	for (int i = 0; i < g.vexnum; i++) {
		res.push_back(make_pair(0, 0));
	}
	for (int i = 0; i < g.vexnum; i++) {
		res[i].second = g.adj[i].size();
		list<int>::const_iterator it = g.adj[i].begin();
		for (; it != g.adj[i].end(); it++) {
			res[*it].first++;
		}
	}
	return res;
}

ALGraph mkALGraph(const char * f) {
	ifstream input;
	input.open(f);
	int a;
	input >> a;
	ALGraph res;
	res.vexnum = a;
	for (int i = 0; i < res.vexnum; i++) {
		int vexn;
		input >> vexn;
		list<int> tmp;
		while (input >> vexn, vexn != -1) {
			tmp.push_back(vexn);
		}
		res.adj.push_back(tmp);
	}
	return res;
}

int main() {
	ALGraph g = mkALGraph("D://f.txt");
	ALGraph mkALGraph(const char * f);	return 0;
}