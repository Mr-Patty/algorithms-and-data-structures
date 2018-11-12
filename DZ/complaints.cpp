#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int h,m,s, h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d", &h,&m,&s, &h2,&m2,&s2);
        vec.push_back(pair<int, int>(h*60*60 + m*60 + s, h2*60*60 + m2*60 + s2));
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (vec[i]->second > vec[j].first()) {
                    break;
                }
            }
        }
    }
    return 0;
}