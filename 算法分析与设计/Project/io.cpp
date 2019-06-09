#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int Graph[1000][1000];
int numv;
int nume;
int numt;
vector<int> T;

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

int main() {
	string filename("b01.stp");
	//cin >> filename;
	cout << filename << endl;
	readFile(filename);
	checkread();
	return 0;
}