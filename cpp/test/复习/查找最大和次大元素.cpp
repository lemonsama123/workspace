#include <bits/stdc++.h> 

using namespace std;

const int INF = 0x3f3f3f3f;

void slove(int a[], int low, int high, int &max1, int &max2) {
	if (low == high) {
		max1 = a[low];
		max2 = -INF;
	} else if (low == high - 1) {
		max1 = max(a[low], a[high]);
		max2 = min(a[low], a[high]);
	} else {
		int mid = (low + high) >> 1;
		int lmax1, lmax2;
		slove(a, low, mid, lmax1, lmax2);
		int rmax1, rmax2;
		slove(a, mid + 1, high, rmax1, rmax2);
		if (lmax1 > rmax1) { 
			max1 = lmax1;
			max2 = max(lmax2, rmax1); 
		} else {
			max1 = rmax1;
			max2 = max(lmax1, rmax2);
		}
	}
}

int main() {
	return 0;
}
