/*
Красивые числа
Многие люди считают цифры 3 и 7 красивыми. Мы же пойдём дальше и будем считать все числа, которые состоят только из троек и семёрок красивыми. А сколько красивых чисел от единицы до N включительно? Посчитайте.

Input format
N

1⩽N⩽1060

Output format
NumberOfFineNumbers
Examples
Input
55

Output
4

Input
100000000000000000000

Output
2097150
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
    string n;
    cin >> n;
    if (n.length() == 1) {
        if (n[0] >= '7')
            cout << 2 << endl;
        else if (n[0] < '3')
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    vector<long long int> a(n.length() + 1);
    vector<long long int> b(n.length() + 1);
    a[0] = 2;
    b[0] = 2;
    for (int i = 1; i < n.length(); i++) {
            a[i] = b[i - 1] * 2 + a[i - 1];
            b[i] = b[i - 1] * 2;
    }
    long long int sum = a[n.length() - 2];
    int j = n.length();
    for (int i = 0; i < n.length(); i++) {
        if (n[i] > '7') {sum += b[j - 1]; break;}
        if ('3' < n[i] && n[i] < '7') {
            if (j -  2 < 0) {
                sum++;
                break;
            }
            sum += b[j - 2];
            break;
        }
        if (n[i] < '3') {
            break;
        }
        if (n[i] == '3') {
            if (j - 1 == 0)
                sum++;
            j--;
        } else if (n[i] == '7') {
            if (j - 2 < 0) {
                sum += b[j - 1];
                break;
            }
            sum += b[j - 2];
            j -= 1;
        }
    }
    cout << sum << endl;
    return 0;
}
