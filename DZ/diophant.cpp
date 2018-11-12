#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c % gcd(a,b) != 0) {
        cout << "No";
        return 0;
    }
    int x = 1;
    int y;
    while (true) {
        int g = c - a * x;
        if (g % b == 0) {
            y = g / b;
            break;
        }
        x++;
    }
    printf("%d %d", x, y);
    return 0;
}
