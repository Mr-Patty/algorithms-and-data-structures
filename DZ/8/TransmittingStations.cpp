#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace::std;

double len(pair<int, int> &a, pair<int, int> &b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int> > station(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        station[i] = make_pair(x, y);
    }
    vector < vector<double > > g(n, vector<double>(n));
    const int INF = 1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                g[i][j] = len(station[i], station[j]);
            }
        }
    }
    vector<bool> used (n);
    vector<double> min_e (n, INF);
    vector<int> sel_e (n, -1);
    min_e[0] = 0;
    double max = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1) {
            if (g[v][sel_e[v]] > max)
                max = g[v][sel_e[v]];
        }

        for (int to = 0; to < n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    cout << fixed << setprecision(4) << max << endl;
    return 0;
}