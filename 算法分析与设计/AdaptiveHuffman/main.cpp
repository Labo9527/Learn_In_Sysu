#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include "Node.h"
#include "Tree.h"
using namespace std;

map<unsigned char, string> init_code;
map<string, unsigned char> init_code2;

string source;
string target;

void init_map() {
	for (int i = 0; i < 256; i++) {
		string sample;
		int t = i;
		for (int j = 0; j < 8; j++) {
			sample.insert(sample.begin(), (i % 2 == 0) ? '0' : '1');
			i >>= 1;
		}
		i = t;
		init_code[unsigned char(i)] = sample;
		init_code2[sample] = unsigned char(i);
	}
}

void encode(ifstream &in, ofstream& out) {
	ifstream in1(source.c_str(), ios::binary);
	char temp1;
	int sum = 0;
	while (true) {
		temp1 = in1.get();
		if (in1.eof())break;
		sum++;
	}
	in1.close();
	tree hft;
	unsigned char temp;
	string help;
	int count = 0;
	while (true) {
		cout << count++ << "/" << sum << endl;
		temp = in.get();
		if (count == 835)
			count = count;
		if (in.eof()) break;
		if (hft.find(temp) == true) {
			if (temp == 'N')
				temp = temp;
			string s1;
			hft.find_code(temp, hft.getRoot(), s1);
			help += s1;
			Node *justfor = hft.FindString(hft.getRoot(), s1);
			Node *s = hft.get(temp);
			s->setFrequency(s->getFrequency() + 1);
			hft.correct_frequency(hft.getRoot());
			hft.update();
			hft.correct_frequency(hft.getRoot());
		}
		else {
			if (temp == 'N')
				temp = temp;
			string s1;
			hft.find_NYT_Code(hft.getRoot(), s1);
			help += s1;
			help += init_code[temp];
			hft.insert(temp);
			hft.correct_frequency(hft.getRoot());
			hft.update();
			hft.correct_frequency(hft.getRoot());
		}
		while (help.length() >= 8) {
			char c1 = '\0';
			for (int i = 0; i < 8; i++) {
				c1 <<= 1;
				if (help[i] == '1')
					c1 = c1 | 1;
			}
			help.erase(help.begin(), help.begin() + 8);
			out.write((char *)&c1, sizeof(unsigned char));
		}
	}
	if (help.length() > 0) {
		char c1 = '\0';
		for (int i = 0; i < help.length(); i++) {
			c1 <<= 1;
			if (help[i] == '1')
				c1 = c1 | 1;
		}
		for (int i = 0; i < 8 - help.length(); i++) {
			c1 <<= 1;
		}
		out.write((char*)&c1, sizeof(unsigned char));
	}
	return;
}

bool theend(string a) {
	if (a.length() > 8)
		return false;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '1')
			return false;
	return true;
}

void decode(ifstream& in, ofstream& out) {

	char temp1;
	ifstream in1(source.c_str(), ios::binary);
	int sum = 0;
	while (true) {
		temp1 = in1.get();
		if (in1.eof())break;
		sum++;
	}
	in1.close();
	int count = 0;

	unsigned char temp = '\0';
	string tohelp;
	tree hft;
	bool thefirst = true;
	bool newchar = false;
	while (true) {
		cout << count++ << "/" << sum << endl;
		if (count == 559)
			count = count;
		temp = in.get();
		if (in.eof()) break;
		for (int i = 0; i < 8; i++) {
			if (temp & 128)
				tohelp += '1';
			else
				tohelp += '0';
			temp <<= 1;
		}
		if (tohelp.length() >= 10000)
			cout << "WARNING" << endl;
		for (int i = 0; i < tohelp.length(); i++) {
			
			if (theend(tohelp))
			break;
			
			Node *s1 = hft.FindString(hft.getRoot(), tohelp.substr(0, i));
			if (s1 != NULL) {
				if (s1->getFrequency() == 0) {

					cout << count++ << "/" << sum << endl;
					temp = in.get();
					for (int i = 0; i < 8; i++) {
						if (temp & 128)
							tohelp += '1';
						else
							tohelp += '0';
						temp <<= 1;
					}

					string s1 = tohelp.substr(i, 8);
					hft.insert(init_code2[s1]);
					char ssr = init_code2[s1];
					out << ssr;
					hft.correct_frequency(hft.getRoot());
					hft.update();
					hft.correct_frequency(hft.getRoot());
					tohelp.erase(tohelp.begin(), tohelp.begin() + i + 8);
					i = 0;
				}
				else {
					out << s1->getData();
					s1->setFrequency(s1->getFrequency() + 1);
					hft.correct_frequency(hft.getRoot());
					hft.update();
					hft.correct_frequency(hft.getRoot());
					tohelp.erase(tohelp.begin(), tohelp.begin() + i);
					i = 0;
				}
			}
		}
	}

	return;

	for (int i = 0; i <= tohelp.length(); i++) {
		Node *s1 = hft.FindString(hft.getRoot(), tohelp.substr(0, i));
		if (s1 != NULL) {
			if (s1->getFrequency() == 0) {
				tohelp.erase(tohelp.begin(), tohelp.begin() + i);

				hft.insert(init_code2[tohelp.substr(0, 8)]);
				hft.correct_frequency(hft.getRoot());
				char ss = init_code2[tohelp.substr(0, 8)];
				out << ss;
				tohelp.erase(tohelp.begin(), tohelp.begin() + 8);

				i = 0;
			}
			else {
				out << s1->getData();
				tohelp.erase(tohelp.begin(), tohelp.begin() + i);
				s1->setFrequency(s1->getFrequency() + 1);
				hft.correct_frequency(hft.getRoot());
				hft.update();
				hft.correct_frequency(hft.getRoot());
				i = 0;
			}
			bool end = true;
			for (int j = 0; j < tohelp.length(); j++) {
				if (tohelp[j] == '1')
					end = false;
			}
			if (end)
				break;
		}
	}

	return;
}

int main() {
	/*
	int choice;
	while (true) {
		cin >> choice;
		if (choice == 1) {
			init_map();
			ifstream in("1.txt", ios::binary);
			ofstream out("2.txt", ios::binary);
			encode(in, out);
			in.close();
			out.close();
		}
		else if (choice == 2) {
			init_map();
			ifstream in("2.txt", ios::binary);
			ofstream out("3.txt", ios::binary);
			decode(in, out);
			in.close();
			out.close();
		}
		else if (choice == 3)
			break;
	}
	return 0;
	*/
	int choice;
	while (true) {
		cout << "欢迎使用自适应哈弗曼压缩程序" << endl;
		cout << "1.压缩程序" << endl;
		cout << "2.解压程序" << endl;
		cout << "3.退出程序" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "输入源文件名 目的文件名" << endl;
			cin >> source >> target;
			double a = clock();
			init_map();
			ifstream in(source.c_str(), ios::binary);
			ofstream out(target.c_str(), ios::binary);
			encode(in, out);
			in.close();
			out.close();
			cout << "压缩用时" << -(a - clock()) / 1000 << "秒" << endl;
		}
		else if (choice == 2) {
			cout << "输入源文件名 目的文件名" << endl;
			cin >> source >> target;
			double a = clock();
			init_map();
			ifstream in(source.c_str(), ios::binary);
			ofstream out(target.c_str(), ios::binary);
			decode(in, out);
			in.close();
			out.close();
			cout << "解压用时" << -(a - clock()) / 1000 << "秒" << endl;
		}
		else if (choice == 3) {
			return 0;
		}
	}
}