#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void expandAroundCenter(const string &s, int left, int right,
                            int &start, int &maxLen) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expandAroundCenter(s, i, i, start, maxLen);

            // Even length palindrome
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};

// ✅ Required for VS Code / g++
int main() {
    Solution sol;
    string s;

    cin >> s;                 // input string
    cout << sol.longestPalindrome(s);

    return 0;
}
