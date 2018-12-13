// Не решенная до конца задача, не получил за нее полный бал
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;


int take(vector<int> &a, int n) {
    int ans_r = 0, sum = 0, sum_min = 0;
    for (int i = 0; i < n; i++) {
        sum_min += a[n-1] - a[i];
    }
    ans_r = n - 1;
    sum = sum_min;
    for (int i = n; i < a.size() - 1; i++) {
        sum = sum + a[i] - a[i - n];
        if (sum < sum_min) {
            ans_r = i;
            sum_min = sum;
        }
    }
    return ans_r + 1;
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
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        sum[i] = v[i] + R;
    }
//    sum[N - 1] = (R - v[N - 1]) + v[0];
//    sum.insert(sum.end(), sum.begin(), sum.end() - 1);
    v.insert(v.end(), sum.begin(), sum.end());
    int k = take(v, N - 1);
    if (k >= N) {
        k = k - N;
    }
    cout << v[k] << endl;
    return 0;
};
