#include <iostream> 

using namespace std;

const int MAX = 101;

int k;
int a[MAX][MAX];

void solve(int k) {
	int i, j, n, t, temp;
	n = 2;
	a[1][1] = 1;
	a[1][2] = 2;
	a[2][1] = 2;
	a[2][2] = 1;
	for (t = 1; t < k; t++) {
		temp = n;
		n = n * 2;
		for (i = temp + 1; i <= n; i++) {
			for (j = 1; j <= temp; j++) {
				a[i][j] = a[i - temp][j] + temp;
			}
		}
		for (i = 1; i <= temp; i++) {
			for (j = temp + 1; j <= n; j++) {
				a[i][j] = a[i + temp][(j + temp) % n];
			}
		}
		for (i = temp + 1; i <= n; i++) {
			for (j = temp + 1; j <= n; j++) {
				a[i][j] = a[i - temp][j - temp];
			}
		}
	}
} 

int main() {
	k = 3;
	int n = 1 << k;
	solve(k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%4d", a[i][j]);
		}
		puts("");
	}
	return 0;
}
