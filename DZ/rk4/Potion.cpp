#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

void func(vector<vector<int> > &graph, int i, int j, int n, int m, int k, int l) {
    if (l == n - i -j)
        return;
    if (graph[i][k - 1] != -1) {
        if (graph[i][k - 1] > graph[i][j]) {
            graph[i][k - 1] = graph[i][j] + 1;
            func(graph, i, k - 1, n, m, k, l);
        }
    } else {
        graph[i][k - 1] = graph[i][j] + 1;
    }
    if (graph[m - 1][j] != -1) {

    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<vector<int> > graph(m, vector<int>(k, -1));
    if (l > n || (n - l > m + k)) {
        cout << "OOPS" << endl;
        return 0;
    }

    return 0;
}
