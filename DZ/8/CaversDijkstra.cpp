#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <set>

using namespace::std;

const int INF = INT_MAX / 2;

int dijkstra(vector<vector <pair<int,int> > > &g, int s, int to, int n) {
    vector<int> d (n, INF);
    d[s] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j = 0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                q.insert (make_pair (d[to], to));
            }
        }
    }
    return d[to];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M, K, S, F;
    cin >> N >> M >> K;
    vector<int> bonfires(K);
    vector<vector <pair<int,int> > > caves(N);
    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;
        bonfires[i] = k - 1;
    }
    for (int i = 0; i < M; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        caves[s - 1].push_back(make_pair(d - 1, w));
        caves[d - 1].push_back(make_pair(s - 1, w));
    }
    cin >> S >> F;


    long long int spel = dijkstra(caves, S - 1, F - 1, N);
    if (spel == INF) {
        cout << -1 << endl;
        return 0;
    }
    long long int bonfire = INF;
    for (int i = 0; i < K; i++) {
        auto temp = dijkstra(caves, bonfires[i], F - 1, N);
        if (temp < bonfire)
            bonfire = temp;
    }
    if (bonfire <= spel) {
        cout << -1 << endl;
    } else {
        cout << spel << endl;
    }
    return 0;
}