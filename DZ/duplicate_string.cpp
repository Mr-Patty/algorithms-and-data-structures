#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prefixFunction(string s, int n) {
    vector<int> p(n);
    for (auto i = 1; i < n; i++) {
        int k = p[i - 1];
        while (k > 0 && s[i] != s[k])
            k = p[k - 1];
        if (s[i] == s[k])
            k++;
        p[i] = k;
    }
    return p;
}

int main() {
    string str;
    cin >> str;
    auto p = prefixFunction(str, str.length());
    cout << p.size() - p[p.size() - 1];
    return 0;
}
