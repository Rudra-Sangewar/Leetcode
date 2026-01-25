#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string res;

        for (auto &it : valueSymbols) {
            while (num >= it.first) {
                res += it.second;
                num -= it.first;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    int num;
    cin >> num;          // example input: 1994
    cout << sol.intToRoman(num);
    return 0;
}
