#include <iostream> 

using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))
#define MAXN 20

int n = 6;
int a[]  = {0, -2, 11, -4, 13, -5, -2};
int dp[MAXN];

void slove() {
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + a[i], a[i]);
	}
} 

void display() {
	int maxj = 1;
	for (int j = 2; j <= n; j++) {
		if (dp[j] > dp[maxj]) {
			maxj = j;
		}
	}
	for (int k = maxj; k >= 1; k--) {
		if (dp[k] <= 0) {
			break;
		}
	}
	printf("	最大连续子序列和：%d\n", dp[maxj]);
	printf("	所选子序列：");
	for (int i = k + 1; i <= maxj; i++) {
		printf("%d ", a[i]);
	}
	puts("");
}

int main() {
	return 0;
}
