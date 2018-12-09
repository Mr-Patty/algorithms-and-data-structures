#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void my_dfs(vector<vector<pair<int, int> > > &g, vector<bool> &used, int cur, int global) {
    used[cur] = true;
    for (unsigned i = 0; i < g[cur].size(); ++i) {
        if (g[cur][i].second != global && !used[g[cur][i].first])
            my_dfs(g, used, g[cur][i].first, global);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M, C;
    cin >> N >> M >> C;
    vector<vector<pair<int, int> > > g(N);
    for (int i = 0; i < M;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    int cn, cs;
    cin >> cn >> cs;
    --cn; --cs;
    vector<int> comp;
    int count = 0;
    for (int i = 1; i <= C; i++) {
        vector<bool> used(N);
        my_dfs(g, used, cs, i);
        if (used[cn]) {
            count++;
            comp.push_back(i);
        }
    }
    sort(comp.begin(), comp.end());
    cout << count << endl;
    for (auto i : comp) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}