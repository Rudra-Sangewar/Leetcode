#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If it's an opening bracket
            if (mapping.find(c) == mapping.end()) {
                st.push(c);
            }
            // If it's a closing bracket
            else if (!st.empty() && mapping[c] == st.top()) {
                st.pop();
            }
            // Mismatch case
            else {
                return false;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    cout << (sol.isValid(s) ? "true" : "false") << endl;

    return 0;
}
