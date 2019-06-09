#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b,long long &x0,long long &y0,long long &p) {
	if (b == 0) {	//原理是辗转相除法
		x0 = 1;
		y0 = 0;
		p = a;
		return p;
	}
	else {
		gcd(b, a%b, y0, x0,p);
		y0 = y0 - a / b * x0;
		return p;							//求解x0,y0,(此时x0,y0的解就是 a==b,b==(a%b)时候的解)
											//求gcd并求解出a*x0+b*y0=gcd，借鉴了 http://www.cnblogs.com/mchcylh/p/5041305.html & https://blog.csdn.net/CharlieLincy/article/details/41801847
	}
}

int main() {
	long long n, costA, costB, passengerA, passengerB;
	long long x0, y0;
	int T = 1;
	while (cin >> n, n) {
		cin >> costA >> passengerA >> costB >> passengerB;
		if (passengerA ==0 && passengerB == 0) {	//容量全为0则无法起飞
			cout << "Data set " << T++ << ": cannot be flown" << endl;
			continue;
		}
		if (passengerA == 0) {						//若A容量为0，则全用B起飞，下一个if分支类似
			if (n%passengerB) {
				cout << "Data set " << T++ << ": cannot be flown" << endl;
				continue;
			}
			cout << "Data set " << T++ << ": " << 0 << " aircraft A, " << (n / passengerB) << " aircraft B" << endl;
			continue;
		}
		if (passengerB == 0) {
			if (n%passengerA) {
				cout << "Data set " << T++ << ": cannot be flown" << endl;
				continue;
			}
			cout << "Data set " << T++ << ": " << (n / passengerA) << " aircraft A, " << 0 << " aircraft B" << endl;
			continue;
		}
		long long p;
		gcd(passengerA, passengerB, x0, y0, p);		//计算出passengerA和passengerB的最大公约数，并且求出passengerA * x0 + passengerB * y0 == gcd 的解
		if (n % p) {							//若无法整除，则比无解
			cout << "Data set " << T++ << ": cannot be flown" << endl;
			continue;
		}
		long long A0 = n / p * x0;				//根据数学公式，有解 nA = A0 + pB / q * t，nB = B0 - pA / q * t		//此公式参考了 https://blog.csdn.net/CharlieLincy/article/details/41801847
		long long B0 = n / p * y0;				//所以我们先构造部分(后面根据性价比来决定参数t)
		long long t;
		if (costA*passengerB <= costB * passengerA) {
			t = floor((double)B0 / (passengerA / p));
		}
		else
			t = ceil((double)- A0 / (passengerB / p));
		A0 = A0 + passengerB / p * t;			//根据参数调整答案
		B0 = B0 - passengerA / p * t;
		cout << "Data set " << T++ << ": " << A0 << " aircraft A, " << B0 << " aircraft B" << endl;
	}
	return 0;
}


