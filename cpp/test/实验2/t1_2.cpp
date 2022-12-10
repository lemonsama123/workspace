#include<iostream>
#include<cmath>

using namespace std;

double slove() {
	double x = 2.0;
	double y = (2 * x * x * x + 1) / (3 * x * x - 3);
	while (abs(x - y) > 10e-9) {
		x = y;
		y = (2 * x * x * x + 1) / (3 * x * x - 3);
	}
	return y;
}

int main() {
	double res = slove();
	printf("%.7f\n", res);
	system("pause");
	return 0;
}