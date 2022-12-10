#include <iostream>

using namespace std;

int a[9];

int gcd(int a, int b) { 
    return b ? gcd(b, a % b) : a;
}

void extend_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extend_euclid(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
}

int inv(int a, int b) {
    int d = gcd(a, b);
    if (d != 1) {
        return -1;
    }
    int x,  y;
    extend_euclid(a, b, x, y);
    return (x % b + b) % b;
}

bool merge(int a1, int m1, int a2, int m2, int &a3, int &m3) {
    int d = gcd(m1, m2);
    int c = a2 - a1;
    if(c % d) {
        return false;
    }
    c = (c % m2 + m2) % m2;
    m1 /= d;
    m2 /= d;
    c /= d;
    c *= inv(m1, m2);
    c %= m2;
    c *= m1 * d;
    c += a1;
    m3 = m1 * m2 * d;
    a3 = (c % m3 + m3) % m3;
    return true;
}

int crt(int a[], int m[], int n) {
    int a1 = a[1];
    int m1 = m[1];
    for(int i=2; i<=n; i++) {
        int a2 = a[i];
        int m2 = m[i];
        int m3, a3;
        if(!merge(a1, m1, a2, m2, a3, m3)) {
            return -1;
        }
        a1 = a3;
        m1 = m3;
    }
    return (a1 % m1 + m1) % m1;
}

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", a + i);
    }
    int m[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int res = crt(a, m, 9);
    printf("%d", res);
    system("pause");
    return 0;
}