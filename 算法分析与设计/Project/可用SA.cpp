#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string>
#include <time.h>
#include <map>

using namespace std;

int numv;
int nume;
int numt;

vector<int> T;
int Graph[1000][1000];

struct solution {
	solution() {
		for (auto i : T) {
			if (find(vertexs.begin(), vertexs.end(), i) == vertexs.end())
				vertexs.push_back(i);
		}
	};
	int add(int a){
		if (find(vertexs.begin(), vertexs.end(), a) == vertexs.end())
			return -1;
		vertexs.push_back(a);
		return 0;
	}
	bool isIn(int a) {
		return find(vertexs.begin(), vertexs.end(), a) != vertexs.end();
	}
	void remove(int a) {
		for (int i = 0; i < vertexs.size(); i++) {
			if (vertexs[i] == a) {
				vertexs.erase(vertexs.begin() + i);
				return;
			}
		}
	}
	solution(vector<int> a) :vertexs(a) {};
	vector<int> vertexs;
};

void readFile(string filename) {
	memset(Graph, -1, sizeof(Graph));
	ifstream in(filename.c_str());
	string s;
	while (getline(in, s)) {
		if (s.substr(0, 5) == string("Nodes")) {
			stringstream help;
			help << s;
			string a;
			help >> a;
			help >> numv;
			//cout << numv << endl;
		}
		else if (s.substr(0, 5) == string("Edges")) {
			stringstream help;
			help << s;
			string a;
			help >> a;
			help >> nume;
			//cout << nume << endl;
		}
		else if (s.substr(0, 9) == string("Terminals")) {
			stringstream help;
			help << s;
			string a;
			help >> a;
			help >> numt;
			//cout << numt << endl;
		}
		else if (s.substr(0, 2) == string("T ")) {
			stringstream help;
			int temp;
			help << s;
			string a;
			help >> a;
			help >> temp;
			//cout << temp << endl;
			T.push_back(temp);
			for (int i = 0; i < numt - 1; i++) {
				stringstream s1;
				getline(in, s);
				//cout << s << endl;
				s1 << s;
				string a;
				s1 >> a;
				s1 >> temp;
				T.push_back(temp);
				//cout << temp << endl;
			}
		}
		else if (s.substr(0, 2) == string("E ")) {
			int e1, e2, e3;
			stringstream help;
			help << s;
			string a;
			help >> a;
			help >> e1 >> e2 >> e3;
			//cout << e1 << e2 << e3 << endl;
			Graph[e1][e2] = Graph[e2][e1] = e3;
			for (int i = 0; i < nume - 1; i++) {
				stringstream s1;
				getline(in, s);
				//cout << s << endl;
				s1 << s;
				string a;
				s1 >> a;
				s1 >> e1 >> e2 >> e3;
				//cout << e1 << e2 << e3 << endl;
				Graph[e1][e2] = Graph[e2][e1] = e3;
			}
		}
	};
}

void checkread() {
	cout << "顶点数：" << numv << endl;
	cout << "边数：" << nume << endl;
	int count = 0;
	for (int i = 1; i <= numv; i++) {
		for (int j = i + 1; j <= numv; j++) {
			if (Graph[i][j] != -1) {
				cout << i << " " << j << " " << Graph[i][j] << endl;
				count++;
			}
		}
	}
	cout << "T点数：" << numt << endl;
	for (int i = 0; i < numt; i++)
		cout << T[i] << endl;
	//cout << count << endl;
	return;
}

bool connect(solution slu) {
	map<int, int> visited;
	int a = slu.vertexs[0];
	queue<int> q;
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 1; i <= numv; i++) {
			if (Graph[t][i]!=-1 && slu.isIn(i) && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	for (auto i : slu.vertexs) {
		if (!visited[i]) return false;
	}
	return true;
}

int distance(int a, int b) {
	int res = 1000000;
	queue<int> q;
	q.push(a);
	int step = 1;
	map<int, int> visited;
	visited[a] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == b) {
			return visited[t];
		}
		for (int i = 1; i <= numv; i++) {
			if (!visited[i] && Graph[t][i] != -1) {
				visited[i] = visited[t]+1;
				q.push(i);
			}
		}
	}
	return res;
}

void printcontent(solution slu) {
	for (auto i : slu.vertexs)
		cout << " " << i << " ";
	cout << endl;
}

int quaility(solution slu) {
	int res = 0;
	if (connect(slu)) {
		cout << "找到一个解！！！！！！！" << endl;
		res = 20000;
		vector<int> helpMST;
		helpMST.push_back(slu.vertexs[0]);
		while (helpMST.size() != slu.vertexs.size()) {
			int next = -1;
			int min = 1000000;
			for (auto i : helpMST) {
				for (int j = 1; j <= numv; j++) {
					if (Graph[i][j] != -1 &&slu.isIn(j) && (find(helpMST.begin(), helpMST.end(), j) == helpMST.end()) && (Graph[i][j] < min || next == -1)) {
						next = j;
						min = Graph[i][j];
					}
				}
			}
			res -= min;
			helpMST.push_back(next);
		}
		return res;
	}
	map<int, int> notation;
	vector<vector<int>> todistance;
	todistance.push_back(vector<int>());
	int block = 1;
	for (auto vertex : slu.vertexs) {
		if (!notation[vertex]) {
			notation[vertex] = block++;
			todistance.push_back(vector<int>());
			todistance[notation[vertex]].push_back(vertex);
		}
		else {
			continue;
		}
		queue<int> q;
		map<int, int> visited;
		q.push(vertex);
		visited[q.front()] = 1;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto i : slu.vertexs) {
				if (!visited[i] && Graph[t][i] != -1) {
					visited[i] = 1;
					notation[i] = notation[t];
					todistance[notation[i]].push_back(i);
					q.push(i);
				}
			}
		}
	}
	res = 10000;
	int min[100][100];
	for (int i = 1; i <= block - 1;i++) {
		for (int j = i + 1; j <= block - 1; j++) {
			min[i][j] = 1000000;
		}
	}
	for (int i = 1; i <= block - 1; i++) {
		for (int j = i + 1; j <= block - 1; j++) {
			for (auto a : todistance[i]) {
				for (auto b : todistance[j]) {
					if (distance(a, b) < min[i][j])
						min[i][j] = distance(a,b);
				}
			}
		}
	}
	for (int i = 1; i <= block - 1; i++) {
		for (int j = i + 1; j <= block - 1; j++) {
			res -= min[i][j];
		}
	}
	return res;
}

solution genbo(solution slu) {
	solution k = slu;
	int r = rand() % numv + 1;
	while (find(T.begin(), T.end(), r) != T.end()) r = rand() % numv + 1;
	if (slu.isIn(r))
		k.remove(r);
	else
		k.vertexs.push_back(r);
	return k;
}

solution SA() {
	srand(time(NULL));
	solution res;
	double Temperature = 10;
	while (Temperature >= 1) {
		cout << "温度: " << Temperature << endl;
		for (int i = 0; i < 100; i++) {
			cout << "温度 " << Temperature << "下循环第 " << i + 1 << " 次,当前解为";
			printcontent(res);
			solution bo = genbo(res);
			int first = quaility(bo);
			int second = quaility(res);
			if (first > second) {
				res = bo;
			}
			else {
				double u = (rand() % 1000) / (double)1000;
				double z = exp((first - second) / (Temperature*Temperature*0.01));
				cout << "温度 " << Temperature << "下转移概率" << " " << z << endl;
				if (u <= z) res = bo;
			}
		}
		Temperature *= 0.9;
	}
	return res;
}

int minMST(solution slu) {
	int res = 0;
	vector<int> helpMST;
	helpMST.push_back(slu.vertexs[0]);
	while (helpMST.size() != slu.vertexs.size()) {
		int next = -1;
		int min = 1000000;
		for (auto i : helpMST) {
			for (int j = 1; j <= numv; j++) {
				if (Graph[i][j] != -1 && slu.isIn(j) && (find(helpMST.begin(), helpMST.end(), j) == helpMST.end()) && (Graph[i][j] < min || next == -1)) {
					next = j;
					min = Graph[i][j];
				}
			}
		}
		res += min;
		helpMST.push_back(next);
	}
	return res;
}

void outedge(solution slu) {
	int start = 0;
	int end = 0;
	int weight = 0;
	cout << "所经过的边有 ";
	vector<int> helpMST;
	helpMST.push_back(slu.vertexs[0]);
	while (helpMST.size() != slu.vertexs.size()) {
		int next = -1;
		int min = 1000000;
		for (auto i : helpMST) {
			for (int j = 1; j <= numv; j++) {
				if (Graph[i][j] != -1 && slu.isIn(j) && (find(helpMST.begin(), helpMST.end(), j) == helpMST.end()) && (Graph[i][j] < min || next == -1)) {
					next = j;
					min = Graph[i][j];
					start = i;
					end = j;
					weight = Graph[i][j];
				}
			}
		}
		helpMST.push_back(next);
		cout << start << "->" << end << ":" << weight << "   ";
	}
}

int main() {
	double start = clock();
	readFile(string("hc6p.stp"));
	checkread();
	solution a = SA();
	int res = minMST(a);
	if (connect(a)) {
		cout << "所得路径为：" << res << endl;
		cout << "包含顶点有：";
		for (auto i : a.vertexs)
			cout << " " << i << " ";
		outedge(a);
		cout << endl;
	}
	else {
		cout << "没有找到解" << endl;
	}
	double end = clock();
	cout << "程序用时: " << (end - start) / 1000 << "秒" << endl;
	return 0;
}