#include "vector.h"
template <typename T>
class Stack :public Vector<T> {
public:
	void push(T const& e) { insert(size(), e); }
	T pop() { return remove(size() - 1); }
	T& top() { return (*this)[size() - 1]; }
};

void convertR(Stack<char>& S, __int64 n, int base) {	//递归实现,应尽量避免递归(有参数空间消耗和调用时间消耗)
	static char digit[] = { '0','1','2','3','4'
	,'5','6','7','8','9','A','B','C','D'
	,'E','F' };
	if (n > 0) {
		convertR(S, n / base, base);
		S.push(digit[n%base]);
	}
}

void convertD(Stack<char>& S, __int64 n, int base) {	//是迭代,但是顺序是反的
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

int divide(const char exp[], int lo, int hi) {//切分表达式exp[lo,hi]
	int mi = lo, crc = 1;
	while ((crc > 0) && (++mi > hi)) {
		if (exp[mi] == ')') crc--;
		if (exp[mi] == '(') crc++;
	}
	return mi;
}

//书上paren有一种递归法，但是效率和可用性差，代码内容也复杂，用到了上面两个函数

bool paren(const char exp[], int lo, int hi) {//迭代版
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

//1.中缀算数表达式计算的函数实在不想写了，书上有，要制优先级表

//2.Infix~RPN