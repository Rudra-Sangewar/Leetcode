#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n < 3) return 1;

        string s = "122";
        char next = '1';
        int ans = 1;  // count of '1's in first 3 chars

        for (int idx = 2; s.size() < n; idx++) {
            if (next == '1') 
                ans += s[idx] - '0';

            s.append(s[idx] - '0', next);

            next = (next == '1') ? '2' : '1';
        }

        if (s.size() > n && s.back() == '1') 
            ans--;

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of '1's in magical string: " 
         << sol.magicalString(n) << endl;

    return 0;
}