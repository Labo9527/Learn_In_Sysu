#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAX_SIZE 10000

typedef  struct {

	int   arcs[MAX_SIZE][MAX_SIZE]; //adjacency matrix of the graph

	int vexnum;// number of vertices

	int arcnum;//number of edges

} AMGraph;

vector<pair<int, int> > degree(const AMGraph &g) {
	vector<pair<int, int>> res;
	for (int i = 0; i < g.arcnum; i++)
		res.push_back(make_pair(0, 0));
	for (int i = 0; i < g.arcnum; i++) {
		for (int j = 0; j < g.arcnum; j++) {
			res[i].second += g.arcs[i][j];
			res[j].first += g.arcs[i][j];
		}
	}
	return res;
}

AMGraph mkAMGraph(const char * f) {
	ifstream input;
	input.open(f);
	int n;
	input >> n;
	AMGraph res;
	res.arcnum = n;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			input >> num;
			res.arcs[i][j] = num;
		}
	}
	return res;
}

int main() {
	AMGraph g = mkAMGraph("D://f.txt");
	AMGraph mkAMGraph(const char * f);	return 0;
}