#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                numSeen = true;
                numAfterE = true;
            }
            else if (c == '.') {
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (c == 'e' || c == 'E') {
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numAfterE = false;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};

int main() {
    Solution sol;

    cout << sol.isNumber("2") << endl;        // 1 (true)
    cout << sol.isNumber("0089") << endl;    // 1
    cout << sol.isNumber("-0.1") << endl;    // 1
    cout << sol.isNumber("1e") << endl;      // 0 (false)
    cout << sol.isNumber("e3") << endl;      // 0
    cout << sol.isNumber("99e2.5") << endl;  // 0

    return 0;
}