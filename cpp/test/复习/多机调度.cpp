#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100;

int n = 7;
int m = 3;

struct NodeType {
	int no;
	int t;
	int mno;
	bool operator<(const NodeType& s) const {
		return t > s.t;
	}
};

NodeType A[] = {{1, 2}, {2, 14}, {3, 4}, {4, 16}, {5, 6}, {6, 5}, {7, 3}};

void slove() {
	NodeType e;
	if (n <= m) {
		printf("为每一个作业分配一台机器\n");
		return;
	}
	sort(A, A + n);
	priority_queue<NodeType> qu;
	for (int i = 0; i < m; i++) {
		A[i].mno = i + 1;
		printf(" 给机器%d分配作业%d，执行时间为%2d，占用时间段：[%d, %d]\n", A[i].mno, A[i].no, A[i].t, 0, A[i].t);
		qu.push(A[i]);
	}
	for (int i = m; i < n; i++) {
		e = qu.top();
		qu.pop();
		printf(" 给机器%d分配作业%d，执行时间为%2d，占用时间段：[%d, %d]\n", e.mno, A[i].no, A[i].t, e.t, e.t + A[i].t);
		e.t += A[i].t;
		qu.push(e);
	}
}

int main() {
	printf("多机调度方案\n");
	slove();
	return 0;
}
