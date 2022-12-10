#include <iostream> 
#include <algorithm>

using namespace std;

void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	puts("");
}

void dfs(int a[], int n, int i) {
	if (i >= n) {
		display(a, n);
		return;
	} 
	for (int j = i; j < n; j++) {
		swap(a[i], a[j]);
		dfs(a, n, i + 1);
		swap(a[i], a[j]);
	}
}

int main() {
	int a[] = {1, 2, 3};
	int n = sizeof(a) / sizeof(int);
	dfs(a, n, 0);
	return 0;
}
