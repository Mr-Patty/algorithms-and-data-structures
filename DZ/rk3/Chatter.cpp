// это не решенная задача, алгоритм правильный, но нужны исправления
// Кажется должна сработать замена vector<vector<int> > на vector<vector<bool> >
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <cmath>ж

using namespace::std;

void func(vector<vector<int> > &vec, vector<pair<int, int> > &send, int &count, int n, int m) {
    if (send.empty())
        return;
    vector<pair<int, int> > new_send;
    for (int i = 0; i < send.size(); i++) {
        int x = send[i].first, y = send[i].second;
        if (x < n - 1 && vec[x + 1][y] != 1) {
            vec[x + 1][y] = 1;
            new_send.push_back(make_pair(x + 1, y));
        }
        if (x > 0 && vec[x - 1][y] != 1) {
            vec[x - 1][y] = 1;
            new_send.push_back(make_pair(x - 1, y));
        }
        if (y < m - 1 && vec[x][y + 1] != 1) {
            vec[x][y + 1] = 1;
            new_send.push_back(make_pair(x, y + 1));
        }
        if (y > 0 && vec[x][y - 1] != 1) {
            vec[x][y - 1] = 1;
            new_send.push_back(make_pair(x, y - 1));
        }
//        auto it = find(send.begin(), send.end(), );
    }
//    send.clear();
    vector<pair<int, int> >().swap(send);
    count++;
    func(vec, new_send, count, n, m);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > vec(n, vector<int>(m));
    vector<pair<int, int> > send(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        send[i] = make_pair(x, y);
        vec[x][y] = 1;
    }
    int count = 0;
    func(vec, send, count, n, m);
    cout << count - 1 << endl;
    return 0;
}