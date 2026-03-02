#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;        
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        // Include element
        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        // Exclude element
        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }    
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3};   // Example input
    
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets are:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (auto &num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}