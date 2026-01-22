#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <= 1) return s;

        vector<string> v(numRows, "");

        int j = 0, dir = -1;

        for (int i = 0; i < s.length(); i++) {

            if (j == numRows - 1 || j == 0)
                dir *= -1;

            v[j] += s[i];

            if (dir == 1)
                j++;
            else
                j--;
        }

        string res;
        for (auto &it : v)
            res += it;

        return res;
    }
};

int main() {
    Solution sol;

    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << sol.convert(s, numRows) << endl;

    return 0;
}
