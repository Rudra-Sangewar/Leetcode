#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        int tp = 0;

        while (sp < s.length() && tp < t.length()) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }

        return sp == s.length();
    }
};

int main() {
    Solution obj;

    string s, t;
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    if (obj.isSubsequence(s, t)) {
        cout << "True ✅ (s is a subsequence of t)" << endl;
    } else {
        cout << "False ❌ (s is NOT a subsequence of t)" << endl;
    }

    return 0;
}