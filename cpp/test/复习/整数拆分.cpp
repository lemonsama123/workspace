#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 500

int dp[MAXN][MAXN];

void slove(int n, int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i == 1 || j == 1) {
				dp[i][j] = 1;
			} else if (i < j) {
				dp[i][j] = dp[i][i];
			} else if (i == j) {
				dp[i][j] = dp[i][j - 1] + 1;
			} else {
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
			}
		}
	}
}

int main() {
	int n = 5, k = 5;
	memset(dp, 0, sizeof(dp));
	slove(n, k);
	printf("(%d, %d) = %d\n", n, k, dp[n][k]);
	return 0;
}
