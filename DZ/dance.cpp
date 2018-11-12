#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    int l;
    cin >> l; cin >> n;

    vector<int> points(n);
    for (auto &point : points)
        cin >> point;

    sort(points.begin(), points.end());

    size_t amount = 0;
    int start = points[0];
    int end = start + 2 * l;
    for (size_t i = 0; i < points.size(); i++)
    {
        while(points[i] <= end && i < n) i++;
        amount++;
        start = points[i];
        end = start + 2 * l;
        if (i == n - 1) amount++;
    }

    cout << amount << endl;

    return 0;
}