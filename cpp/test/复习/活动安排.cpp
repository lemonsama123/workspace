#include <bits/stdc++.h> 

using namespace std;

const int MAX = 51;

struct Action {
	int b;
	int e;
	bool operator<(const Action& s) const {
		return e <= s.e;
	}
};

int n = 11;
Action A[] = {{0}, {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 15}};
bool flag[MAX];
int cnt = 0;

void slove() {
	memset(flag, 0,sizeof(flag));
	sort(A + 1, A + n + 1);
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i].b >= pre) {
			pre = A[i].e;
			flag[i] = true;
		}
	}
}

int main() {
	slove();
	printf("求解结果\n");
	printf("选取的活动：");
	for (int i = 1; i <= n; i++) {
		if (flag[i]) {
			printf("[%d %d] ", A[i].b, A[i].e);
			cnt++;
		}
	}
	printf("\n共%d个活动\n", cnt);
	return 0;
} 
