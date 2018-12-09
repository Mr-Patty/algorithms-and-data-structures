#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace::std;

const vector<char> alph =
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
         'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
         'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

pair<int, int> str2pair(string str) {
    auto it = find (alph.begin(), alph.end(), str[0]);
    return make_pair(stoi(str.substr(1)) - 1, it - alph.begin());
}

char num2char(int n) {
    return alph[n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;
    vector<vector<int> > g(N, vector<int>(N));
    int n = N;
    pair<int, int> s = str2pair(s1);
    pair<int, int> end = str2pair(s2);
    queue<pair<int, int> > q;
    q.push (s);
    vector<vector<bool> > used(N, vector<bool>(N));
    vector<vector<int> > d(N, vector<int>(N));
    vector<vector<pair<int, int> > > p(N, vector<pair<int, int> >(N, make_pair(-1, -1)));
    used[s.first][s.second] = true;
    p[s.first][s.second] = make_pair(-1, -1);

    int x[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int y[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (temp == end)
            break;
        for (int i = 0; i < 8; i++) {
            int nx = temp.first + x[i];
            int ny = temp.second + y[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && used[nx][ny] == false) {
                used[nx][ny] = true;
                q.push(std::make_pair(nx, ny));
                d[nx][ny] = d[temp.first][temp.second] + 1;
                p[nx][ny] = temp;

            }
        }
    }
    if (!used[end.first][end.second])
        cout << 0 << endl;
    else {
        cout << d[end.first][end.second] << endl;

        vector <std::pair <int, int> > way;
        while (end != s) {
            way.push_back(end);
            end = p[end.first][end.second];
        }
        way.push_back(s);
        for (int i = way.size() - 2; i >= 0; i--) {
            cout << num2char(way[i].second) << way[i].first + 1 << endl;
        }
        cout << endl;
    }
    return 0;
}