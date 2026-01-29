#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1️⃣ Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If only spaces
        if (i == n) return 0;

        // 2️⃣ Handle sign
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        // 3️⃣ Convert digits
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // 4️⃣ Clamp overflow
            if (sign == 1 && res > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -res < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(res * sign);
    }
};

// Optional: for local testing
int main() {
    Solution sol;
    cout << sol.myAtoi("   -42") << endl;
    cout << sol.myAtoi("4193 with words") << endl;
    cout << sol.myAtoi("21474836460") << endl;
    return 0;
}
