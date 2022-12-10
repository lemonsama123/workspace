#include <iostream>

using namespace std;

int n = 4;
int W = 6;
int w[] = {0, 5, 3, 2, 1};
int v[] = {0, 4, 4, 3, 1};

int x[10];

int maxv = 0;

void dfs(int i, int tw, int tv, int rw, int op[]) {
	if (i > n) {
		if (tw == W && tv > maxv) {
			maxv = tv;
			for (int i = 1; i <= n; i++) {
				x[i] = op[i];
			} 
		}
		return;
	} 
	op[i] = 1;
	if (tw + w[i] <= W) {
		dfs(i + 1, tw + w[i], tv + v[i], rw - w[i], op);
	}
	op[i] = 0;
	if (tw + rw - w[i] >= W) {
		dfs(i + 1, tw, tv, rw - w[i], op);
	}
}

int main() {
	return 0;
}
