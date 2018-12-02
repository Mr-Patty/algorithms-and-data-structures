#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace:: std;

int main(int argc, const char * argv[])
{
    string s;
    cin >> s;
    int maxWeight = 0;
    cout << s.substr(1) << endl;
//    for (int i = 1; i < s.size() + 1; i++) {
//        unordered_map<string, int> weights(s.size() - (i - 1));
//        for (int j = 0; j < s.size() - (i - 1); j++) {
//            weights[s.substr(j, i)] += 1;
//        }
////        int maxNum = 0;
////        for (auto obj: m) {
////            if (obj.second > maxNum) {
////                maxNum = obj.second;
////            }
////        }
////        int weight = maxNum * (i + 1);
////        if (weight > maxWeight) {
////            maxWeight = weight;
////        }
//        for (auto val : weights) {
//            if (val.second * i > maxWeight)
//                maxWeight = val.second * i;
//        }
//
//    }

    cout << maxWeight << endl;
    return 0;
}