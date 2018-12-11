#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector < vector<int> > g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            g[i][j] = x * (-1);
        }
    }
    const int MAX = 100000000;
    vector<bool> used (n);
    vector<int> max_e (n, MAX), sel_e (n, -1);
    max_e[0] = 0;
    long long int sum = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || max_e[j] < max_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1)
            sum += g[v][sel_e[v]];

        for (int to = 0; to < n; ++to)
            if (g[v][to] < max_e[to]) {
                max_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    cout << -1 * sum << endl;
    return 0;
}