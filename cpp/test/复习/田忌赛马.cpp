#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1001;

int n;
int a[MAX];
int b[MAX];

int ans = 0;

void solve() {
	sort(a, a + n);
	sort(b, b + n);
	ans = 0;
	int lefta = 0, leftb = 0;
	int righta = n - 1, rightb = n - 1;
	while (lefta <= righta) {
		if (a[righta] > b[rightb]) {
			ans += 200;
			righta--;
			rightb--; 
		} else if (a[righta] < b[rightb]) {
			ans -= 200;
			lefta++;
			rightb--;
		} else {
			if (a[lefta] > b[leftb]) {
				ans += 200;
				lefta++;
				leftb++;
			} else {
				if (a[lefta] < b[rightb]) {
					ans -= 200;
				}
				lefta++;
				rightb--;
			}
		}
	}
}

int main() {
	while (true) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", b + i);
		}
		solve();
		printf("%d\n", ans);
	}
	return 0;
}
