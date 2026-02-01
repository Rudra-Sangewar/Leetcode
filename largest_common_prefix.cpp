#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if (v.empty()) return "";

        sort(v.begin(), v.end());

        string ans = "";
        string first = v[0];
        string last = v[v.size() - 1];

        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            ans += first[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> v = {"flower", "flow", "flight"};

    cout << sol.longestCommonPrefix(v) << endl;
    return 0;
}
