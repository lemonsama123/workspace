#include <iostream>

using namespace std;

double slove() {
    double l = 1;
    double r = 3;
    while (r - l > 10e-9) {
        double mid = (l + r) / 2;
        double t = mid * mid * mid - 3 * mid - 1;
        if (t > 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    double res = slove();
    printf("%.7f\n", res);
    system("pause");
    return 0;
}