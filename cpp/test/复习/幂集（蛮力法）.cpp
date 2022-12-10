#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 10;

void inc(int b[], int n) {
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			b[i] = 0;
		} else {
			b[i] = 1;
			break;
		}
	}
}

void solve(int a[], int b[], int n) {
	int pw = (int) pow(2, n);
	printf("1~%dµÄÃÝ¼¯£º\n", n);
	for (int i = 0; i < pw; i++) {
		printf("{ ");
		for (int k = 0; k < n; k++) {
			if (b[k]) {
				printf("%d ", a[k]);
			}
		}
		printf("} ");
		inc(b, n);
	}
	puts("");
}

int main() {
	int n = 3;
	int a[MAX], b[MAX];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		b[i] = 0;
	}
	solve(a, b, n);
	return 0;
}
