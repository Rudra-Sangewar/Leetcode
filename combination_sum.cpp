#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void summation(vector<vector<int>>& ans,
                   vector<int>& candi,
                   vector<int>& digits,
                   int tar, int k, int start) {

        if (k == tar) {
            ans.push_back(digits);
            return;
        }

        for (int i = start; i < candi.size(); i++) {
            if (k + candi[i] <= tar) {
                digits.push_back(candi[i]);
                summation(ans, candi, digits, tar, k + candi[i], i);
                digits.pop_back(); // backtrack
            } else {
                break; // pruning (because sorted)
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candi, int tar) {
        vector<vector<int>> ans;
        vector<int> digits;
        sort(candi.begin(), candi.end());
        summation(ans, candi, digits, tar, 0, 0);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations:\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int x : comb) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
