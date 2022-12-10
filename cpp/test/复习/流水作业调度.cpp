#include <iostream>
#include <algorithm>

using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))

const int N = 100;

int n = 4;
int a[N] = {5, 12, 4, 8};
int b[N] = {6, 2, 14, 7};

struct NodeType {
	int no;
	bool group;
	int time;
	bool operator<(const NodeType& s) const {
		return time < s.time;
	}
};

int best[N];

int slove() {
	int i, j, k;
	NodeType c[N];
	for (int i = 0; i < n; i++) {
		c[i].no = i;
		c[i].group = (a[i] <= b[i]);
		c[i].time = a[i] <= b[i] ? a[i] : b[i];
	}
	sort(c, c + n);
	j = 0;
	k = n - 1;
	for (i = 0; i < n; i++) {
		if (c[i].group == 1) {
			best[j++] = c[i].no;
		} else {
			best[k--] = c[i].no;
		}
	}
	int f1 = 0;
	int f2 = 0;
	for (i = 0; i < n; i++) {
		f1 += a[best[i]];
		f2 = max(f2, f1) + b[best[i]];
	}
	return f2;
}

int main() {
	printf("求解结果\n");
	printf(" 总时间：%d\n", slove());
	printf(" 调度方案：");
	for (int i = 0; i < n; i++) {
		printf("%d ", best[i] + 1);
	}
	puts("");
	return 0;
}
