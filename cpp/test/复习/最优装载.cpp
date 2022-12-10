#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 20;

int w[] = {0, 5, 2, 6, 4, 3};
int n = 5, W = 10;
int maxw;
int x[MAX];

void solve() {
	memset(x, 0, sizeof(x));
	sort(w + 1, w + n + 1);
	maxw = 0;
	int restw = W;
	for (int i = 1; i <= n && w[i] <= restw; i++) {
		x[i] = 1;
		restw -= w[i];
		maxw += w[i];
	}
}

int main() {
	solve();
	printf("最优方案\n");
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) {
			printf("选取重量为%d的集装箱\n", w[i]);
		}
	}
	printf("总重量=%d\n", maxw);
	return 0; 
}
