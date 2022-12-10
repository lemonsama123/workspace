#include <iostream>

using namespace std;

int solve(int a[], int n) {
	int max_sum = 0;
	int cur_sum = 0;
	for (int i = 0; i < n; i++) {
		cur_sum += a[i];
		if (cur_sum < 0) {
			cur_sum = 0;
		} 
		if (max_sum < cur_sum) {
			max_sum = cur_sum;
		}
	}
	return max_sum;
}

int main() {
	int a[] = {-2, 11, -4, 13, -5, -2};
	int b[] = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2};
	printf("%d\n", solve(a, sizeof(a)/sizeof(int)));
	printf("%d\n", solve(a, sizeof(a)/sizeof(int)));
	return 0;
}
