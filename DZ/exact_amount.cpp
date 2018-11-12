#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

bool amount(vector<int> &v, int sum, int &x, int &y) {
    bool flag = false;

    for (size_t i = 0; i < v.size(); i++) {
        if (sum - v[i] < v[i])
            break;
        int it = binarySearch(v, i + 1, v.size(), sum - v[i]);
        if (it != -1) {
            x = v[i];
            y = v[it];
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> V(N);
    vector<int> P(M);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        V[i] = x;
    }
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        P[i] = x;
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < M; i++) {
        int x = 0, y = 0;
        int flag = amount(V, P[i], x, y);
        if (flag)
            printf("%d %d\n", x, y);
        else
            printf("Not found\n");
    }
};
