#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> res;

int slove(int m, int n) {
	vector<vector<int>> t;
	int decaliter = 10;
	int a = 0, b = 0;
	int total = 0;
	while (decaliter != 5) { 
		if (a == 0) { 
			decaliter -= m; 
			a += m; 
			total++;
			vector<int> v;
			v.push_back(10);
			v.push_back(m);
			v.push_back(m);
			t.push_back(v);
		} 
		if (a > 0 && b < n) {
			if (b + a <= n) {
				b += a;
				total++;
				vector<int> v;
				v.push_back(m);
				v.push_back(n);
				v.push_back(a);
				t.push_back(v);
				a -= a; 
			} else { 
				a -= n - b; 
				total++;
				vector<int> v;
				v.push_back(m);
				v.push_back(n);
				v.push_back(n - b);
				t.push_back(v);
				b = n; 
			} 
		} 
		if (b == n) { 
			b -= n;
			decaliter += n;
			total++;
			vector<int> v;
			v.push_back(n);
			v.push_back(10);
			v.push_back(n);
			t.push_back(v);
		}
		if (m >= n) { 
			if (a == 5) break; 
		} 
		else { 
			if (b == 5)break; 
		} 
	}
	res.push_back(t);
	return total; 
} 

int main() { 
	int t1 = slove(3, 7);
	int t2 = slove(7, 3);
	int min;
	if (t1 < t2) {
		min = t1;
		for (int i = 0; i < res[0].size(); i++) {
			printf("第 %d 步：%d L 容器向 %d L 容器倒入 %d L 油\n", i + 1, res[0][i][0], res[0][i][1], res[0][i][2]);
		}
	} else {
		min = t2;
		for (int i = 0; i < res[1].size(); i++) {
			printf("第 %d 步：%d L 容器向 %d L 容器倒入 %d L 油\n", i + 1, res[1][i][0], res[1][i][1], res[1][i][2]);
		}
	}
	printf("最少步数为：%d\n", min);
    system("pause");
	return 0; 
}
