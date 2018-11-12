#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;


int take(vector<int> &a, int n) {
    int ans = a[0],
            ans_l = 0,
            ans_r = 0,
            sum = 0,
            sum_min = 0,
            minus_pos = -1;
    for (int i = 0; i < n; i++) {
        sum_min += a[i];
    }
    ans_r = n - 1;
    sum = sum_min;
    for (int i = n; i < a.size() - 1; i++) {
        sum = sum + a[i] - a[ans_l];
        if (sum < sum_min) {
            ans_r = i;
            ans_l = ans_r - n + 1;
            sum_min = sum;
        }
    }
    return ans_r;
}

int main()
{
    int N, R;
    cin >> N >> R;
    vector<int> v(N);
    vector<int> sum(N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        v[i] = x;
    }
    for (int i = 0; i < N - 1; i++) {
        sum[i] = v[i + 1] - v[i];
    }
//    sum.insert()
    sum[N - 1] = (R - v[N - 1]) + v[0];
    sum.insert(sum.end(), sum.begin(), sum.end() - 1);


    return 0;
};
