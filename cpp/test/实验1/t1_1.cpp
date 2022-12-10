#include <iostream>

using namespace std;

int a[9];

void slove() {
    for (int i = 1; i <= INT32_MAX; i++) {
        if (i % 10 == a[0] &&
            i % 9 == a[1] &&
            i % 8 == a[2] &&
            i % 7 == a[3] &&
            i % 6 == a[4] &&
            i % 5 == a[5] && 
            i % 4 == a[6] &&
            i % 3 == a[7] &&
            i % 2 == a[8]) {
                printf("%d\n", i);
                return;
            }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", a + i);
    }
    slove();
    system("pause");
    return 0;
}