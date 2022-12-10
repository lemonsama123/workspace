#include <iostream>

using namespace std;

#define N 9

void dfs(char op[], int sum, int prev_add, int a[], int i) {
	if (i == N) {
		if (sum == 100) {
			printf(" %d", a[0]);
			for (int i = 1; i < N; i++) {
				if (op[i] != ' ') {
					printf("%c", op[i]);
				}
				printf("%d", a[i]);
			}
			printf("=100\n");
		}
		return;
	}
	
	op[i] = '+';
	sum += a[i];
	dfs(op, sum, a[i], a, i + 1);
	sum -= a[i];
	
	op[i] = '-';
	sum -= a[i];
	dfs(op, sum, -a[i], a, i + 1);
	sum += a[i];
	
	op[i] = ' ';
	sum -= prev_add;
	int tmp;
	if (prev_add > 0) {
		tmp = prev_add * 10 + a[i];
	} else {
		tmp = prev_add * 10 - a[i];
	}
	sum += tmp;
	dfs(op, sum, tmp, a, i + 1);
	sum -= tmp;
	sum += prev_add;
}

int main() {
	char op[9];
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	dfs(op, 0, 0, a, 0);
	return 0;
}
