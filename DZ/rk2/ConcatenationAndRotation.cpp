#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int get(const string & str, int index) {
    int v = 0;
    for(int i = index; i < str.size(); ++i) {
        switch (str[i]) {
            case '(':
                ++v;
                break;
            case ')':
                --v;
                break;
            default:
                break;
        }

        if (v == 0) {
            return i + 1;
        }

    }
    return str.size();
}

string concat(const string & str, int s, int e) {
    string cur = "";
    string l = "";
    for(int i = s; i < e; ++i) {
        char s = str[i];
        if (s == '(') {
            cur += l;
            int b = get(str, i);
            l = concat(str, i + 1, b - 1);
            i = b - 1;
        }
        else if (s == 'R') {
            reverse(l.begin(), l.end());
        }
        else if (s == ',') {
            cur += l;
            l = "";
        }
        else {
            l += s;
        }
    }
    cur += l;
    return cur;
}


int main()
{
    string str;
    cin >> str;
    cout << concat(str, 0, str.size()) << endl;
};