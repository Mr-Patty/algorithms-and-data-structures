#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace::std;

void dfs(int cur, vector<vector<int> > &adj, vector<bool> &used) {
    used[cur] = true;
    for (int i=0;i<adj[cur].size();++i) {
        int nxt = adj[cur][i];
        if (!used[nxt])
            dfs(nxt, adj, used);
    }
}

int find_comps(vector<vector<int> > &adj, vector<bool> &used, int n) {
    int cnt = 0;
    for (int i=0; i < n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i) {
        if (!used[i]) {
            dfs(i, adj, used);
            ++cnt;
        }
    }
    return cnt;
}

bool dfs_check(int cur, vector<vector<int> > &adj, vector<bool> &used, int end) {
    used[cur] = true;
    bool tmp = false, c = false;
    if (adj[cur].empty())
        return false;
    for (int i = 0; i < adj[cur].size();++i) {
        int nxt = adj[cur][i];
        if (!used[nxt]) {
            if (nxt == end)
                return true;
            c = dfs_check(nxt, adj, used, end);
        }
        if (c) {
//            tmp = true;
            return true;
        }
    }
    return tmp;
}

bool check(vector<vector<int> > &g, vector<bool> &used, int n, int x, int y) {
    for (int i=0; i < n; ++i)
        used[i] = false;
    queue<int> q;
    q.push (x);
    used[x] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == y)
            return true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (to == y)
                return true;
            if (!used[to]) {
                used[to] = true;
                q.push (to);
            }
        }
    }
    return false;
//    return dfs_check(x, adj, used, y);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int v, e, m;
    cin >> v >> e >> m;
    vector<vector<int> > g(v);
    vector<bool> used(v);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<pair<int, int> >M(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        M[i] = make_pair(x, y);
    }
    int ch = find_comps(g, used, v);
    cout << ch << endl;
    for (int i = 0; i < m; i++) {
        auto xt = find(g[M[i].first].begin(), g[M[i].first].end(), M[i].second);
        if (xt != g[M[i].first].end())
            g[M[i].first].erase(xt);
        auto yt = find(g[M[i].second].begin(), g[M[i].second].end(), M[i].first);
        if (yt != g[M[i].second].end())
            g[M[i].second].erase(yt);
        bool res = check(g, used, v, M[i].first, M[i].second);
        if (!res)
            ch++;
        cout << ch << endl;
//        cout << find_comps(g, used, v) << endl;
    }
    return 0;
}