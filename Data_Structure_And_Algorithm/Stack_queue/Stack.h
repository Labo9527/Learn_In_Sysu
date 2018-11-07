#include "vector.h"
template <typename T>
class Stack :public Vector<T> {
public:
	void push(T const& e) { insert(size(), e); }
	T pop() { return remove(size() - 1); }
	T& top() { return (*this)[size() - 1]; }
};

void convertR(Stack<char>& S, __int64 n, int base) {	//�ݹ�ʵ��,Ӧ��������ݹ�(�в����ռ����ĺ͵���ʱ������)
	static char digit[] = { '0','1','2','3','4'
	,'5','6','7','8','9','A','B','C','D'
	,'E','F' };
	if (n > 0) {
		convertR(S, n / base, base);
		S.push(digit[n%base]);
	}
}

void convertD(Stack<char>& S, __int64 n, int base) {	//�ǵ���,����˳���Ƿ���
	static char digit[] = { '0','1','2','3','4'
		,'5','6','7','8','9','A','B','C','D'
		,'E','F' };
	while(n > 0) {
		S.push(digit[n%base]);
		n /= base;
	}
}

void trim(const char exp[], int& lo, int &hi) {//exp[lo,hi]
	while ((lo <= hi) && (exp[lo] != '(') && (exp[lo] != ')'))	lo++;
	while ((lo <= hi) && (exp[hi] != '(') && (exp[hi] != ')'))	hi--;
}

int divide(const char exp[], int lo, int hi) {//�зֱ��ʽexp[lo,hi]
	int mi = lo, crc = 1;
	while ((crc > 0) && (++mi > hi)) {
		if (exp[mi] == ')') crc--;
		if (exp[mi] == '(') crc++;
	}
	return mi;
}

//����paren��һ�ֵݹ鷨������Ч�ʺͿ����Բ��������Ҳ���ӣ��õ���������������

bool paren(const char exp[], int lo, int hi) {//������
	Stack<char> S;
	for (int i = 0; exp[i]; i++) {
		switch (exp[i])
		{
		case '(':
		case '[':
		case '{':
			S.push(exp[i]); break;
		case ')':if ((S.empty() || S.pop() != '(')) return false; break;
		case ']':if ((S.empty() || S.pop() != '[')) return false; break;
		case '}':if ((S.empty() || S.pop() != '{')) return false; break;
		}
	}
	return S.empty();
}

//1.��׺�������ʽ����ĺ���ʵ�ڲ���д�ˣ������У�Ҫ�����ȼ���

//2.Infix~RPN