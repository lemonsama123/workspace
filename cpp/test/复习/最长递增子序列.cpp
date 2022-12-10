#include <iostream>

using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))

const int MAX = 100;

int ans = 0;
int dp[MAX];

void solve(int a[], int n) {
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	ans = dp[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, dp[i]);
	}
}

int main() {
	int a[] = {2, 1, 5, 3, 6, 4, 8, 7, 9};
	int n = sizeof(a) / sizeof(a[0]);
	solve(a, n);
	printf("求解结果\n");
	printf("\t最长递增子序列长度：%d\n", ans);
	return 0;
} 
