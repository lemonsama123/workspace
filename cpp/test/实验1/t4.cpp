#include <iostream>

using namespace std;

void display (int a, int b, int n) {
    for (int i = a; i < b; i++) {
        printf("%d+", i);
    }
    printf("%d=%d\n", b, n);
}

void slove(int n) {
    int total = 0;
    for (int i = 1; i < (n >> 1) + 1; i++) {
        int sum = i;
        for (int j = i + 1; j <= (n >> 1) + 1; j++) {
            sum += j;
            if (sum == n) {
                total++;
                display(i, j, n);
                break;
            }
            if (sum > n) {
                break;
            }
        }
    }
    printf("一共有%d个不同的连续自然数段\n", total);
} 

int main() {
    int n;
    scanf("%d", &n);
    slove(n);
    system("pause");
    return 0;
}