#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;

        // Step 1: find first decreasing element from right
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }

        // If the array is in descending order
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: find element just larger than nums[i-1]
        int j = n - 1;
        while (nums[j] <= nums[i - 1]) {
            j--;
        }

        // Step 3: swap
        swap(nums[i - 1], nums[j]);

        // Step 4: reverse the suffix
        reverse(nums.begin() + i, nums.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
