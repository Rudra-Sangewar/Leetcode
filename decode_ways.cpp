#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');  // faster than stoi

            if (one >= 1 && one <= 9) {
                dp[i] += dp[i - 1];
            }

            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Number of ways to decode: " << sol.numDecodings(s) << endl;

    return 0;
}