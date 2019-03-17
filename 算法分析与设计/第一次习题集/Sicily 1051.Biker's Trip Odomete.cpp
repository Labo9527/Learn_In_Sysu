#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double d, speed, time;
	int count = 0;
	while (cin >> d) {
		cin >> speed >> time;
		if (speed == 0)
			break;
		double a = 3.1415927*d*speed / (5280 * 12);
		printf("Trip #%d: ", ++count);
		printf("%.2f %.2f",a,(a/time)*3600);
		printf("\n");
	}
	return 0;
}