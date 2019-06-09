#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b,long long &x0,long long &y0,long long &p) {
	if (b == 0) {	//ԭ����շת�����
		x0 = 1;
		y0 = 0;
		p = a;
		return p;
	}
	else {
		gcd(b, a%b, y0, x0,p);
		y0 = y0 - a / b * x0;
		return p;							//���x0,y0,(��ʱx0,y0�Ľ���� a==b,b==(a%b)ʱ��Ľ�)
											//��gcd������a*x0+b*y0=gcd������� http://www.cnblogs.com/mchcylh/p/5041305.html & https://blog.csdn.net/CharlieLincy/article/details/41801847
	}
}

int main() {
	long long n, costA, costB, passengerA, passengerB;
	long long x0, y0;
	int T = 1;
	while (cin >> n, n) {
		cin >> costA >> passengerA >> costB >> passengerB;
		if (passengerA ==0 && passengerB == 0) {	//����ȫΪ0���޷����
			cout << "Data set " << T++ << ": cannot be flown" << endl;
			continue;
		}
		if (passengerA == 0) {						//��A����Ϊ0����ȫ��B��ɣ���һ��if��֧����
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
		gcd(passengerA, passengerB, x0, y0, p);		//�����passengerA��passengerB�����Լ�����������passengerA * x0 + passengerB * y0 == gcd �Ľ�
		if (n % p) {							//���޷�����������޽�
			cout << "Data set " << T++ << ": cannot be flown" << endl;
			continue;
		}
		long long A0 = n / p * x0;				//������ѧ��ʽ���н� nA = A0 + pB / q * t��nB = B0 - pA / q * t		//�˹�ʽ�ο��� https://blog.csdn.net/CharlieLincy/article/details/41801847
		long long B0 = n / p * y0;				//���������ȹ��첿��(��������Լ۱�����������t)
		long long t;
		if (costA*passengerB <= costB * passengerA) {
			t = floor((double)B0 / (passengerA / p));
		}
		else
			t = ceil((double)- A0 / (passengerB / p));
		A0 = A0 + passengerB / p * t;			//���ݲ���������
		B0 = B0 - passengerA / p * t;
		cout << "Data set " << T++ << ": " << A0 << " aircraft A, " << B0 << " aircraft B" << endl;
	}
	return 0;
}


