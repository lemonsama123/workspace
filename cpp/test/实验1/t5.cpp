#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int sum = 0, nn = 0, ans = 0;
deque<int> dq;

void dfs(int n) {
    for (int i = n; i >= 1; i--) {
        dq.push_back(i);
        sum += i;
        if (sum > nn) {
            sum -= i;
            dq.pop_back();
        } else if (sum == nn) {
            for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
                if (it == dq.begin()) {
                    printf("%d", *it);
                } else {
                    printf(" %d", *it);
                }
            } 
            cout << endl;
            sum -= i;
            ans++;
            dq.pop_back();
        } else {
            dfs(i);
            sum -= i;
            dq.pop_back();
        }
    }
}

int main() {
    printf("请输入n：");
    scanf("%d", &nn);
    dfs(nn);
    printf("total = %d", ans);
	system("pause");
    return 0;
}