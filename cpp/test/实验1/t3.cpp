#include <iostream>

using namespace std;

bool check(int a, int b, int c, int d, int e) {
    int t = (10 * a + b) * (100 * c + 10 * d + e);
    if (t >= 1000 && t <= 9999) {
        int i = t % 10;
        t /= 10;
        int h = t % 10;
        t /= 10;
        int g = t % 10;
        t /= 10;
        int f = t;
        if (f != g && f != h && f != i && f !=0 &&
            g != h && g != i && g != 0 &&
            h != i && h != 0 &&
            i != 0 &&
            f != a && f != b && f != c && f != d && f != e &&
            g != a && g != b && g != c && g != d && g != e &&
            h != a && h != b && h != c && h != d && h != e &&
            i != a && i != b && i != c && i != d && i != e) {
                return true;
        }
    }
    return false;
}

int main() {
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            if (a != b) {
                for (int c = 1; c <= 9; c++) {
                    if (c != a && c != b) {
                        for (int d = 1; d <= 9; d++) {
                            if (d != a && d != b && d != c) {
                                for (int e = 1; e <= 9; e++) {
                                    if (e != a && e != b && e != c && e != d) {
                                        if (check(a, b, c, d, e)) {
                                            printf("%d × %d = %d\n", (10 * a + b), (100 * c + 10 * d + e), (10 * a + b) * (100 * c + 10 * d + e));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}