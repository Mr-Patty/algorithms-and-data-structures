#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


//long long int fib(long long int n, long long int mod) {
////    vector<long long int> f(n);
//    long long int y = 0;
//    long long int x = 1;
////    long long int res = 0;
//    for (long long int i = 1; i < n; i++) {
//        x += y;
//        y = (x - y) % mod;
//    }
//    return x % mod;
//}

long long int fib(int n, int mod)
{
    long long int a = 0, ta,
            b = 1, tb,
            c = 1, rc = 0,  tc,
            d = 1, rd = 1;

    while (n)
    {
        if (n & 1)
        {
            tc = rc;
            rc = (rc*a + rd*c) % mod;
            rd = (tc*b + rd*d) % mod;
        }

        ta = a; tb = b; tc = c;
        a = (a*a  + b*c) % mod;
        b = (ta*b + b*d) % mod;
        c = (c*ta + d*c) % mod;
        d = (tc*tb+ d*d) % mod;

        n >>= 1;
    }
    return rc % mod;
}

int main() {
    long long int n, mod;
    cin >> n >> mod;
    cout << fib(n, mod);
    return 0;
}