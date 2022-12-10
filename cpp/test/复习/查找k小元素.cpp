#include <bits/stdc++.h>

using namespace std;

int quick_select(int a[], int s, int t, int k) {
	int i = s, j = t, tmp;
	if (s < t) {
		tmp = a[s];
		while (i != j) {
			while (j > i && a[j] >= tmp) {
				j--;
			}
			a[i] = a[j];
			while (i < j && a[i] < tmp) {
				i++;
			}
			a[j] = a[i];
		}
		a[i] = tmp;
		if (k - 1 == i) {
			return a[i];
		} else if (k - 1 < i) {
			return quick_select(a, s, i - 1, k);
		} else {
			return quick_select(a, i + 1, t, k);
		}
	} else if (s == t && s == k - 1) {
		return a[k - 1];
	}
}

int main() {
	return 0;
} 
