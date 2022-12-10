#include <iostream>
#include <cstring>
#include <vector>
#include <string>
 
using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))

const int MAX = 51; 

int m, n;
string a, b;
int dp[MAX][MAX];
vector<char> subs;
 
void LCS() {
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= n; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
}

void build_subs() {
	int k = dp[m][n];
	int i = m; 
	int j = n;
	while (k > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		} else {
			subs.push_back(a[i - 1]);
			i--;
			j--;
			k--;
		}
	}
}
 
int main() {
	a = "abcbdb";
	b = "acbbabdbb";
	m = a.length();
	n = b.length();
	LCS();
	build_subs();
	printf("求解结果\n");
	cout << "\ta: " << a << endl;
	cout << "\tb: " << b << endl;
	printf("\t最长公共子序列：");
	for (int i = subs.size() - 1; i >= 0; i--) {
		printf("%c", subs[i]);
	}
	puts("");
	printf("\t长度：%d", dp[m][n]);
	return 0;
}

