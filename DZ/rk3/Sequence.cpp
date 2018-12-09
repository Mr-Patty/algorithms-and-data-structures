#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace::std;

long long int func(int x, int p1, int p2, int p3) {
    vector<long long int> vec = {1};
    for (int i = 0; i <= x; i++) {
        long long int max = LONG_LONG_MAX;
        for (int j = 0; j < vec.size(); j++) {
            long long int tmp1 = vec[j] * p1;
            long long int tmp2 = vec[j] * p2;
            long long int tmp3 = vec[j] * p3;
            if (tmp1 > vec[i] && tmp1 < max)
                max = tmp1;
            if (tmp2 > vec[i] && tmp2 < max)
                max = tmp2;
            if (tmp3 > vec[i] && tmp3 < max)
                max = tmp3;
        }
        vec.push_back(max);
    }
    return vec[x - 1];

}

int main() {
    std::ios_base::sync_with_stdio(false);
    long long int p1, p2, p3, n;
    cin >> p1 >> p2 >> p3 >> n;
    cout << func(n, p1, p2, p3) << endl;
    return 0;
}