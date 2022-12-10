#include<iostream>
#include<iomanip>
using namespace std;

const int N = 100;

int a[N][N];
int n;

int f(int i, int j) {
	if (i != 0 && j != 0 && (i + j) < n) {
		if ((i + j) % 2 == 1) {
			a[i][j] = f(i - 1, j + 1) + 1;
		}
		if ((i + j) % 2 == 0) {
			a[i][j] = f(i + 1, j - 1) + 1;
		}
	}
	if (i + j >= n) {
		a[i][j] = n * n + 1 - f(n - 1 - i, n - 1 - j); 
	}
	if (i == 0 && j % 2 == 1) {
		a[i][j] = f(i, j - 1) + 1;
	} else if (i == 0 && j % 2 == 0 && j != 0) {
		a[i][j] = f(i + 1, j - 1) + 1; 
	} else if (j == 0 && i % 2 == 1) { 
		a[i][j] = f(i - 1, j + 1) + 1;
	} else if (j == 0 && i % 2 == 0 && i != 0) {
		a[i][j] = f(i - 1, j) + 1;
	}
	return a[i][j];
}

void slove() {
	a[0][0] = 1;
	for(int i = 0;i < n; i++) {
		for (int j = 0; j < n; j++) {
			f(i, j);
		}
	}
}

void display() {
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
			if (j == n - 1) {			
                puts("");
            }
		}
    }
}

int main() {
	printf("输入n：");
	scanf("%d", &n);
	slove();
	display();
    system("pause");
    return 0;
}
