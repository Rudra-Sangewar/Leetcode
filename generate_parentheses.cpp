#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;        
    }

private:
    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        // if the string length is 2*n, it's a valid combination
        if (openP == n && closeP == n) {
            res.push_back(s);
            return;
        }

        // add '(' if we still can
        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        // add ')' only if it won't break validity
        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
};

// Optional: for local testing
int main() {
    Solution sol;
    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);

    for (auto &s : ans) {
        cout << s << endl;
    }

    return 0;
}
