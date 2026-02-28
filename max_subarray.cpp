#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0;
        int maxTillNow = INT_MIN;

        for (int c : nums) {
            curMax = max(c, curMax + c);
            maxTillNow = max(maxTillNow, curMax);
        }

        return maxTillNow;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl;

    return 0;
}