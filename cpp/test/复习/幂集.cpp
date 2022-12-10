#include <iostream> 

using namespace std;

void display(int a[], int n, int x[]) {
	for (int i = 0; i < n; i++) {
		if (x[i]) {
			printf("%d ", a[i]); 
		}
	}
	puts("");
}

void dfs(int a[], int n, int i, int x[]) {
	if (i >= n) {
		display(a, n, x);
	} else {
		x[i] = 1;
		dfs(a, n, i + 1, x);
		x[i] = 0;
		dfs(a, n, i + 1, x);
	}
}

int main() {
	int x[3];
	int a[] = {1, 2, 3};
	dfs(a, 3, 0, x);
	return 0;
}
