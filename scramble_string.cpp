#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // for storing already solved problems
    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {

        // base cases
        int n = s1.size();

        // if both strings are not equal in size
        if (s2.size() != n)
            return false;

        // if both strings are equal
        if (s1 == s2)
            return true;

        // if size is 1 and strings are not equal
        if (n == 1)
            return false;

        string key = s1 + " " + s2;

        // check if already solved
        if (mp.find(key) != mp.end())
            return mp[key];

        // try every partition
        for (int i = 1; i < n; i++) {

            // Case 1: Without Swap
            bool withoutswap =
                isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i));

            if (withoutswap)
                return mp[key] = true;

            // Case 2: With Swap
            bool withswap =
                isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i));

            if (withswap)
                return mp[key] = true;
        }

        return mp[key] = false;
    }
};

int main() {

    Solution obj;

    string s1 = "great";
    string s2 = "rgeat";

    if (obj.isScramble(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}