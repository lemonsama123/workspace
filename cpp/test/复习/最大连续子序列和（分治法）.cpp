#include <iostream>

using namespace std;

long max(long a, long b, long c) {
	if (a < b) {
		a = b; 
	} 
	if (a > c) {
		return a;
	}
	return c;
}

long solve(int a[], int left, int right) {
	if (left == right) {
		if (a[left] > 0) {
			return a[left];
		} else {
			return 0;
		}
	}
	int mid = (left + right) >> 1;
	long max_left_sum = solve(a, left, mid);
	long max_right_sum = solve(a, mid + 1, right);
	long max_left_border_sum = 0;
	long left_border_sum = 0;
	for (int i = mid; i >= left; i--) {
		left_border_sum += a[i];
		if (left_border_sum > max_left_border_sum) {
			max_left_border_sum = left_border_sum;
		}
	}
	long max_right_border_sum = 0;
	long right_border_sum = 0;
	for (int i = mid + 1; i <= right; i++) {
		right_border_sum += a[i];
		if (right_border_sum > max_right_border_sum) {
			max_right_border_sum = right_border_sum;
		}
	}
	return max(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

int main() {
	int a[] = {-2, 11, -4, 13, -5, -2};
	int n = 6;
	int b[] = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2};
	int m = 12;
	printf("a 序列的最大连续子序列和：%ld\n", solve(a, 0, n - 1));
	printf("b 序列的最大连续子序列和：%ld\n", solve(b, 0, m - 1));
	return 0; 
}
