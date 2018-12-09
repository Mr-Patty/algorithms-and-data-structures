#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace::std;

int main() {
    std::ios_base::sync_with_stdio(false);
    unsigned long long n, k;
    cin >> n >> k;
    vector<unsigned long long int> without(n + 1), with(n + 1);
    without[1] = k - 1;
    with[1] = 0;
    for (int i = 2; i <= n; i++) {
        without[i] = (k - 1) * (with[i - 1] + without[i - 1]);
        with[i] = without[i - 1];
    }
    cout << with[n] + without[n] << endl;
    return 0;
}