#include <bits/stdc++.h>

using namespace std;

#define MAX 1025

int k;
int x, y;
int board[MAX][MAX];
int tile = 1;

void solve(int tr, int tc, int dr, int dc, int size) {
	if (size == 1) {
		return; 
	}
	int t = tile++;
	int s = size >> 1;
	if (dr < tr + s && dc < tc + s) {
		solve(tr, tc, dr, dc, s);
	} else {
		board[tr + s - 1][tc + s - 1] = t;
		solve(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr < tr + s && dc >= tc + s) {
		solve(tr, tc + s, dr, dc, s);
	} else {
		board[tr + s - 1][tc + s] = t;
		solve(tr, tc + s, tr + s - 1, tc + s, s);
	}
	if (dr >= tr + s && dc < tc + s) {
		solve(tr + s, tc, dr, dc, s);
	} else {
		board[tr + s][tc + s - 1] = t;
		solve(tr + s, tc, tr + s, tc + s - 1, s);
	} 
	if (dr >= tr + s && dc >= tc + s) {
		solve(tr + s, tc + s, dr, dc, s);
	} else {
		board[tr + s][tc + s] = t;
		solve(tr + s, tc + s, tr + s, tc + s, s); 
	}
}

int main() {
	k = 3;
	x = 1;
	y = 2;
	int size = 1 << k;
	solve(0, 0, x, y, size); 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%4d", board[i][j]);
		}
		puts("");
	}
	return 0;
}
