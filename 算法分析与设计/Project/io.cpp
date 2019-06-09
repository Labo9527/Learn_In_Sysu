#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <map>
#include <queue>

using namespace std;

struct edge {
	int start;
	int end;
	int distance;
	edge() {};
	edge(int a1, int a2, int a3) :start(a1), end(a2), distance(a3) {};
	bool operator ==(const edge& a) {
		return a.start == start && a.end == end && a.distance == distance;
	}
	bool operator < (const edge&a) const {
		return distance < a.distance;
	}
};

int Graph[1000][1000];
int numv;
int nume;
int numt;
vector<int> T;
vector<edge> E;


int readFile(string filename) {
	ifstream in(filename.c_str());
	string s;
	while (getline(in,s)) {
		//cout << s << endl;
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
			E.push_back(edge(e1, e2, e3));
			E.push_back(edge(e2, e1, e3));
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
				E.push_back(edge(e1, e2, e3));
				E.push_back(edge(e2, e1, e3));
			}
		}
	};
	return 0;
}

void checkread() {
	cout << "顶点数：" << numv << endl;
	cout << "边数：" << nume << endl;
	int count = 0;
	for (int i = 1; i <= numv; i++) {
		for (int j = i + 1; j <= numv; j++) {
			if (Graph[i][j] != 0) {
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

bool connect(vector<edge> solution) {
	if (solution.size() == 0)
		return false;
	vector<int> nodes;
	map<int, int> visited;
	map<edge, int> used;
	bool fs = true;
	bool sc = true;
	for (int i = 0; i < solution.size(); i++) {
		if (find(nodes.begin(), nodes.end(), solution[i].start) == nodes.end())
			nodes.push_back(solution[i].start);
		if (find(nodes.begin(), nodes.end(), solution[i].end) == nodes.end())
			nodes.push_back(solution[i].end);
	}
	queue<int> q;
	q.push(nodes[0]);
	visited[nodes[0]] = 1;

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int j = 0; j < solution.size(); j++) {
			if (solution[j].start == t) {
				if (!visited[solution[j].end]) {
					q.push(solution[j].end);
					visited[solution[j].end] = 1;
				}
			}
			else if (solution[j].end == t) {
				if (!visited[solution[j].start]) {
					q.push(solution[j].start);
					visited[solution[j].start] = 1;
				}
			}
		}
	}

	for (int i = 0; i < nodes.size(); i++) {
		if (!visited[nodes[i]]) {
			return false;
		}
	}
	return true;
}

bool nocycle(vector<edge> solution) {
	if (solution.size() == 0)
		return true;
	vector<int> nodes;
	map<int, int> visited;
	map<edge, int> used;
	bool fs = true;
	bool sc = true;
	for (int i = 0; i < solution.size(); i++) {
		if (find(nodes.begin(), nodes.end(), solution[i].start) == nodes.end())
			nodes.push_back(solution[i].start);
		if (find(nodes.begin(), nodes.end(), solution[i].end) == nodes.end())
			nodes.push_back(solution[i].end);
	}
	queue<int> q;
	q.push(nodes[0]);
	visited[nodes[0]] = 1;

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < solution.size(); i++) {
			if (solution[i].start == t && !used[solution[i]]) {
				used[solution[i]] = 1;

				if (visited[solution[i].end]) {
					return false;
				}

				else {
					visited[solution[i].end] = 1;
					q.push(solution[i].end);
				}
			}
			else if (solution[i].end == t && !used[solution[i]]) {
				used[solution[i]] = 1;
				if (visited[solution[i].start]) {
					return false;
				}
				else {
					visited[solution[i].start] = 1;
					q.push(solution[i].start);
				}
			}
		}
	}
	return true;
}

int quaility(vector<edge> solution) {
	int res = 0;
	res += 5000;
	map<int, int> book;
	int totaldistance = 0;
	for (int j = 0; j < solution.size(); j++) {
		totaldistance += solution[j].distance;
	}
	for (int i = 0; i < numt; i++) {
		for (int j = 0; j < solution.size(); j++) {
			if ((solution[j].start == T[i] || solution[j].end == T[i]) && !book[T[i]]) {
				book[T[i]] = 1;
				res = res + 100;
			}
		}
	}
	res += (100 - totaldistance);

	if (solution.size() == 0)
		return res;

	//return res;
	//检验是否是一个树
	
	/*
	vector<int> nodes;
	map<int, int> visited;
	map<edge, int> used;
	bool fs = true;
	bool sc = true;
	for (int i = 0; i < solution.size(); i++) {
		if (find(nodes.begin(), nodes.end(), solution[i].start) == nodes.end())
			nodes.push_back(solution[i].start);
		if (find(nodes.begin(), nodes.end(), solution[i].end) == nodes.end())
			nodes.push_back(solution[i].end);
	}
	queue<int> q;
	q.push(nodes[0]);
	visited[nodes[0]] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < solution.size(); i++) {
			if (solution[i].start == t && !used[solution[i]]){
				used[solution[i]] = 1;
				
				if (visited[solution[i].end]) {
					if (fs) {
						fs = false;
						res -= 100;
					}
				}
				
				else {
					visited[solution[i].end] = 1;
					q.push(solution[i].end);
				}
			}
			else if (solution[i].end == t && !used[solution[i]]) {
				used[solution[i]] = 1;
				if (visited[solution[i].start]) {
					if (fs) {
						fs = false;
						res -= 100;
					}
				}
				else {
					visited[solution[i].start] = 1;
					q.push(solution[i].start);
				}
			}
		}
	}
	
	for (int i = 0; i < nodes.size(); i++) {
		if (!visited[nodes[i]]) {
			res -= 100;
			break;
		}
	}
	*/

	if (connect(solution) == false) {
		vector<int> nodes;
		map<int, int> notation;
		map<edge, int> used;
		for (int i = 0; i < solution.size(); i++) {
			if (find(nodes.begin(), nodes.end(), solution[i].start) == nodes.end())
				nodes.push_back(solution[i].start);
			if (find(nodes.begin(), nodes.end(), solution[i].end) == nodes.end())
				nodes.push_back(solution[i].end);
		}
		for (int i = 0; i < nodes.size(); i++) {
			if (!notation[nodes[i]]) {
				res -= 10;
				queue<int> q;
				q.push(nodes[i]);
				notation[nodes[i]] = 1;
				while (!q.empty()) {
					int t = q.front();
					q.pop();
					for (int j = 0; j < solution.size(); j++) {
						if (solution[j].start == t) {
							if (!notation[solution[j].end]) {
								q.push(solution[j].end);
								notation[solution[j].end] = 1;
							}
						}
						else if (solution[j].end == t) {
							if (!notation[solution[j].start]) {
								q.push(solution[j].start);
								notation[solution[j].start] = 1;
							}
						}
					}
				}
			}
		}
	}
	if (nocycle(solution) == false) {
		res -= 100;
	}
	return res;
}

vector<edge> genbo(vector<edge> solution) {
	int a = 0;
	vector<int> nodes;
	for (int i = 0; i < solution.size(); i++) {
		if (find(nodes.begin(), nodes.end(), solution[i].start) == nodes.end())
			nodes.push_back(solution[i].start);
		if (find(nodes.begin(), nodes.end(), solution[i].end) == nodes.end())
			nodes.push_back(solution[i].end);
	}

	vector<edge> res = solution;
	if ((rand() % 4 == 0 && solution.size()!= 0)||2*solution.size()==E.size()) {
		int del = rand() % solution.size();
		res.erase(res.begin() + del);
	}
	else {
		if (solution.size() == 0) {
			for (int i = 0; i < T.size(); i++) {
				for (int j = 0; j < E.size(); j++) {
					if (T[i] == E[j].start || T[i] == E[j].end) {
						if (find(res.begin(), res.end(), E[j]) == res.end())
							res.push_back(E[j]);
						break;
					}
				}
			}
			return res;
		}
		while (true) {
			//cout << a++ << endl;
			int add = rand() % E.size();
			edge ee = edge(E[add].end, E[add].start, E[add].distance);
			if (find(solution.begin(), solution.end(), E[add])!=solution.end())
				continue;
			if (find(solution.begin(), solution.end(), ee)!=solution.end())
				continue;
			if ((find(nodes.begin(), nodes.end(), E[add].start) == nodes.end()) && (find(nodes.begin(), nodes.end(), E[add].end) == nodes.end()))
				continue;
			res.push_back(E[add]);
			break;
		}
	}
	return res;
}

vector<edge> SA() {
	vector<edge> inital;
	for (int i = 0; i < T.size(); i++) {
		for (int j = 0; j < E.size(); j++) {
			if (T[i] == E[j].start || T[i] == E[j].end) {
				if(find(inital.begin(),inital.end(),E[j])==inital.end())
					inital.push_back(E[j]);
				break;
			}
		}
	}
	double T = 2000;
	while (true) {
		cout << "温度: " << T << endl;
		for (int i = 0; i < 100; i++) {
			//if (i % 100 == 0)
			//	cout << i << endl;
			vector<edge> nebo = genbo(inital);
			//cout << quaility(nebo) << " " << quaility(inital) << endl;
			if (quaility(nebo) >= quaility(inital)) {
				inital = nebo;
			}
			else {
				double num = (rand() % 100)*0.01;
				//cout << quaility(inital) << " " << quaility(nebo) << endl;
				double z = exp(-(quaility(inital) - quaility(nebo)) / (0.01*T));
				//cout << z << endl;
				if (num <= z) inital = nebo;
			}
		}
		T = 0.9*T;
		if (T < 10)
			break;
	}
	return inital;
}

void printInfo(vector<edge> solution) {
	cout << "所得解信息如下" << endl;
	map<int, int> cover;
	bool flag = true;
	for (int i = 0; i < T.size(); i++) {
		for (int j = 0; j < solution.size(); j++) {
			if (solution[j].start == T[i] || solution[j].end == T[i])
				cover[T[i]] = 1;
		}
		if (!cover[T[i]]) {
			cout << T[i] << "未被覆盖" << endl;
			flag = false;
		}
	}
	if (flag) {
		cout << "全部T顶点被覆盖完毕" << endl;
	}
	if (connect(solution))
		cout << "连通性良好" << endl;
	else
		cout << "不连通" << endl;
	if (nocycle(solution))
		cout << "不成环" << endl;
	else
		cout << "成环" << endl;
	cout << "总路程:";
	int sum = 0;
	for (int i = 0; i < solution.size(); i++)
		sum += solution[i].distance;
	cout << sum << endl;
}

int main() {
	srand(time(NULL));
	string filename("p401.stp");
	//cin >> filename;
	cout << filename << endl;
	readFile(filename);
	checkread();
	vector<edge> res=SA();
	printInfo(res);
	return 0;
}