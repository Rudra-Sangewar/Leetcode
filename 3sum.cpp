#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } 
                else if (total < 0) {
                    j++;
                } 
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // skip duplicates for second and third elements
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = sol.threeSum(nums);

    for (auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
