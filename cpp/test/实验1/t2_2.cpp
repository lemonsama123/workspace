#include<iostream>
#define M 100
#define N 100
using namespace std;
int a[M][N] = { 0 };

void slove(int n, int s) {
	int k = 0;
	int i = 0;
	int j = 0;
	int m = 1;
	a[0][0] = m;
	while (m < n * s) {
		switch (k) {
			case 0:
				if (i + j < s - 1) {
					j++; 
					m++;
					a[i][j] = m;
					k = (k + 1) % 4;
				} else {
					i++; 
					m++;
					a[i][j] = m;
					k = (k + 1) % 4;
				}
				break;
			case 1:
				while (i < n - 1 && j > 0) {
					i++;
					j--;
					m++;
					a[i][j] = m;
				}
				k = (k + 1) % 4;
				break;
			case 2: 
				if (i + j < n - 1) {
					i++;
					m++;
					a[i][j] = m;
					k = (k + 1) % 4;
				} else {
					j++;
					m++;
					a[i][j] = m;
					k = (k + 1) % 4;
				}
				break;
			case 3:
				while (i > 0 && j < s - 1) {
					i--;
					j++;
					m++;
					a[i][j] = m;
				}
				k = (k + 1) % 4;
				break;
		}
	}
}

void display(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d\t", a[i][j]);
		}
		puts("");
	}
}

int main() {
	int r, c;
	scanf("%d%d", &r, &c);
	slove(r, c);
	display(r, c);
	system("pause");
	return 0;
}