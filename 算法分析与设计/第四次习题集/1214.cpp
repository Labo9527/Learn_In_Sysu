#include <iostream>

using namespace std;


//4294967296 429467296

int Check1(int num1,long long L) {
	
	if (num1 == 0)
		return 0;
	long long num2 = num1;
	while (num1) {		//这个循环做的事情就是将二进制串镜像复制并拼接
		num2 = (num2 << 1) | (num1 & 1);
		num1 >>= 1;
	}
	if (num2 <= L)
		return 1;
	return 0;
}

int Check2(int num1,long long L) {
	int res = 0;
	int bit = 0;
	//long long int num2;
	int num3 = 0;
	//num2 = num1;
	long long num4 = num1;
	long long num5 = num1;
	while (num1) {
		num3 = (num3 << 1) | (num1 & 1);
		num1 >>= 1;
		bit++;
	}
	num4 = (num4 << (bit + 1)) | num3;
	num5 = (((num5 << 1) | 1) << bit) | num3;
	if (num4 && num4 <= L)
		res++;
	if (num5 && num5 <= L)
		res++;
	return res;
}

int main() {
	long long L;
	long long res = 0;
	cin >> L;
	
	for (int i = 0; i <= L&&i < (1 << 16); i++) {	//我们为了降低时间复杂度，只遍历一半的二进制串（因为回文的性质），由2^32变为了2^16
		//if (Check1(i, L))   //检测是否以此二进制串为一半构成的回文二进制串仍在[1,L]范围中
			res += Check1(i, L);
		if (i < (1 << 15))		//检测是否以此二进制位一半且中间位为0/1的二进制串为回文串
			res += Check2(i,L);
	}
	cout << res << endl;		//参考了CSDN的实现，主要是两个CHECK函数
	return 0;
}