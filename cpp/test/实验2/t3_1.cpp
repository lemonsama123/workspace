#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

int a[] = {0, 3, 5, 10, 16, 21};
int b[] = {0, 17, 15, 7, 4, 2};
int s[6], dp[6];
vector<int> res;
int price = 22;

void preprocessor(int n) {
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = b[i] - s[i];
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] < 0) {
            dp[i] = dp[i - 1];
        } else if (s[i] * 1.0 / i > s[i - 1] * 1.0 / (i - 1)) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = i;
        }
    }
}

void slove(int n) {
    // if (n <= 0) {
    //     return;
    // }
    // res.push_back(dp[n]);
    // slove(n - dp[n]);
    while (n > 0) {
        res.push_back(dp[n]);
        n -= dp[n];
    }
}

void display() {
    int total = 0;
    for (int i = 0; i < res.size(); i++) {
        printf("第%d年卖出\n", res[i]);
        total += price - s[res[i]];
    }
    printf("用车费用共%d万元\n", total);
}

int main() {
    preprocessor(5);
    slove(5);
    display();
    system("pause");
    return 0;
}