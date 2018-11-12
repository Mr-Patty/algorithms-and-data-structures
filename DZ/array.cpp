#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


bool foo(vector<int> a, int &ans_l, int &ans_r, int n, int v) {
    int sum = 0;
    ans_l = 0;
    ans_r = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > v) {
            while (sum > v && ans_l <= i) {
                sum -= a[ans_l];
                ans_l++;
            }
        }
        if (sum == v) {
            ans_r = i;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    int sum = 0;
    for (int i = 0; i< n; i++) {
        int x;
        scanf("%d", &x);
        arr.push_back(x);
        sum += x;
    }
//    sort(arr.begin(), arr.end());
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        int k = 0, l = 0;
        if (x > sum) {
            cout << "Not found" << endl;
            continue;
        }
        if (foo(arr, k, l, n, x)) {
            cout << k+1 << " " << l+2 << endl;
        } else
            cout << "Not found" << endl;

    }
    return 0;
}