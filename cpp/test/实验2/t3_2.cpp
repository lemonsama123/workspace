#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

int a[N];
int b[N];
int s[N], dp[N];
vector<int> res;
int price;

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
    int n;
    printf("请输入年数：");
    scanf("%d", &n);
    printf("请输入车价：");
    scanf("%d", &price);
    printf("请输输入维护车每年费用：");
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    printf("请输输入每年二手车的价格：");
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    preprocessor(n);
    slove(n);
    display();
    system("pause");
    return 0;
}