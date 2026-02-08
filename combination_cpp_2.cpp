#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        dfs(candidates, target, 0, comb, res);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int start,
             vector<int>& comb, vector<vector<int>>& res) {
        
        if (target == 0) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            comb.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, comb, res);
            comb.pop_back();
        }
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    for (auto &v : result) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
