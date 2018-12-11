/* Дороги и взятки
        В некой стране имеется N городов, между которыми имеется сеть двунаправленных дорог такая, что из любого города можно доехать в любой другой. Расстояние между городами описывается симметричной матрицей смежности C[N,N]. Лоббисты транспортной компании обратили внимание правительства на то, что на содержание дорог требуются средства и протолкнули закон о платном проезде: весь проезд по территории страны сделать платным; стоимость проезда пропорциональна расстоянию. Так как несознательные жители могли воспользоваться альтернативными путями передвижения, часть дорог решили закрыть совсем. Оппозиция настояла на том, чтобы оставшихся дорог было достаточно для того, чтобы проехать из любого города в любой другой.

Ваша задача — определить сумму длин всех дорог, оставшихся после реализации этого решения.

4⩽N⩽10000

0⩽Ci,j⩽109

Input format
N
        C11 C12 C13 ... C1N

        C21 C22 C23 ... C2N

        ...

        CN1 CN2 CN3 ... CNN

        Output format
        MaxLeftRoadLength
Examples
        Input
5
0 5 0 6 10
5 0 0 1 6
0 0 0 5 6
6 1 5 0 0
10 6 6 0 0

Output
28
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector < vector<int> > g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            g[i][j] = x * (-1);
        }
    }
    const int MAX = 100000000;
    vector<bool> used (n);
    vector<int> max_e (n, MAX), sel_e (n, -1);
    max_e[0] = 0;
    long long int sum = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || max_e[j] < max_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1)
            sum += g[v][sel_e[v]];

        for (int to = 0; to < n; ++to)
            if (g[v][to] < max_e[to]) {
                max_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    cout << -1 * sum << endl;
    return 0;
}