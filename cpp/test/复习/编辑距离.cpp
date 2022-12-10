#include <iostream>
#include <string>

using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

const int MAX = 201;

string a = "sfdqxbw";
string b = "gfdgw";

int dp[MAX][MAX];

void solve() {
	for (int i = 1; i <= a.length(); i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= b.length(); j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
}

int main() {
	solve();
	printf("求解结果\n");
	printf("\t编辑距离为：%d\n", dp[a.length()][b.length()]);
	return 0;
}
