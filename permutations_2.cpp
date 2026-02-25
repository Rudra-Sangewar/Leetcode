#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int>> &res) {
        if (i == j - 1) {
            res.push_back(num);
            return;
        }

        for (int k = i; k < j; k++) {
            // Skip duplicates
            if (i != k && num[i] == num[k]) continue;

            swap(num[i], num[k]);
            recursion(num, i + 1, j, res);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2};   // Example input
    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "Unique Permutations:\n";
    for (auto &perm : result) {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}