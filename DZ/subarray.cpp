#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    long long int n, x;
    scanf("%lld", &n);
    vector<long long int> vec;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        vec.push_back(x);
    }
    long long int ans = vec[0], sum = 0, min_sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];
        ans = max (ans, sum - min_sum);
        min_sum = min (min_sum, sum);
    }
    printf("%lld", ans);
    return 0;
}
