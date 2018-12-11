/*
Минимальное расстояние
На плоскости расположено 2⩽N⩽500000 различных точек с вещественными координатами. Требуется найти пару таких точек, расстояние между которыми минимально.

Input format
N

X1

X2

...

XN

Output format
Требуется вывести минимальное расстояние из всех возможных пар точек с десятью знаками после запятой и сами точки в порядке возрастания их номеров в исходном файле. Нумерация точек начинается с единицы. Если имеются пары точек с одинаковым расстоянием, то вывести пару с наименьшими номерами.

Examples
Input
5
1 1
-3 3
-3 -3
3 -3
3 3

Output
2.8284271247 1 5
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

const int MAXN = 500000;

struct Point {
    double x, y;
    int id;
    Point(double x, double y, int i) : x(x), y(y), id(i) {}
    Point() : x(0), y(0), id(0) {}
};

inline bool cmp_x (const Point & a, const Point & b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const Point & a, const Point & b) {
    return a.y < b.y;
}

vector<Point> a(MAXN);

double mindist;
int ansa, ansb;

inline void upd_ans (const Point & a, const Point & b) {
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + .0);
    if (dist < mindist) {
        mindist = dist,  ansa = a.id,  ansb = b.id;
    }
    else if (dist == mindist) {
        if (a.id < ansa) {
            mindist = dist, ansa = a.id,  ansb = b.id;
        } else if (a.id == ansa && b.id < ansb) {
            mindist = dist, ansa = a.id,  ansb = b.id;
        }

    }
}

void rec (int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; ++i)
            for (int j = i + 1; j <= r; ++j)
                upd_ans (a[i], a[j]);
        sort (a.begin() + l, a.begin() + r + 1, &cmp_y);
        return;
    }

    int m = (l + r) >> 1;
    auto midx = a[m].x;
    rec (l, m),  rec (m + 1, r);
    static vector<Point> t(MAXN);
    merge (a.begin() + l, a.begin() + m + 1, a.begin() + m + 1, a.begin() + r + 1, t.begin(), &cmp_y);
    copy (t.begin(), t.begin() + r - l + 1, a.begin() + l);

    int tsz = 0;
    for (int i = l; i <= r; ++i)
        if (abs (a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans (a[i], t[j]);
            t[tsz++] = a[i];
        }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        a[i] = Point(x, y, i + 1);
    }

    sort (a.begin(), a.begin() + n, &cmp_x);
    mindist = 1E20;
    rec (0, n-1);
    cout << fixed << setprecision(10) << mindist << " ";
    if (ansa < ansb)
        cout << ansa << " " << ansb << endl;
    else
        cout << ansb << " " << ansa << endl;
    return 0;
}