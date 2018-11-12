#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
const int N = 20000000;


vector<char> sieve2() {
    vector<char> S (N + 1, 1);
    S[0] = S[1] = 0;
    for (int i = 2; i * i <= N; ++i)
        if (S[i])
            if (i * i <= N)
                for (int j = i * i; j <= N; j += i)
                    S[j] = 0;
    return S;
}

int count(vector<char> part) {
    int sum = 0;
    for (auto it : part) {
        sum += it;
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    auto erast = sieve2();
    int number = count(vector<char>(erast.begin() + 2, erast.begin() + n + 2));
    int j = -1;
    for (int i = 2; i < N - n; i++) {
        if (number == m) {
            j = i;
            break;
        }
        if (erast[i] == 1) number--;
        if (erast[i + n] == 1) number++;
    }
    cout << j;
    return 0;
}
