#include <iostream>

using namespace std;

int slove(int n) {
    int total = 0;
    for ( int i = n / 10; i >= 0; i--) {
        for (int j = n - i * 10; j >= 0; j--) {
            for (int k = n - i * 10 - j * 5; k >= 0; k--) {
                int m = n - i * 10 - j * 5 - k * 2;
                if (m >= 0) { 
                    total++;
                    printf("第%d种换法：一元%d张，二元%d张，五元%d张，十元%d张\n", total, m + 1, k + 1, j + 1, i + 1);
                }
            }
        }
    }
    return total;
}

int main() {
    int n = 100 - 1 - 2 - 5 - 10;
    int total = slove(n);
    printf("共%d种换法\n", total);
    system("pause");
    return 0;
}