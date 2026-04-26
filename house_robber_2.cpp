#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];

        return max(getMax(nums, 0, nums.size() - 2),
                   getMax(nums, 1, nums.size() - 1));
    }

private:
    int getMax(vector<int>& nums, int start, int end) {
        int prevRob = 0, maxRob = 0;

        for (int i = start; i <= end; ++i) {
            int temp = max(maxRob, prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }

        return maxRob;
    }
};

int main() {
    Solution obj;

    vector<int> nums;
    int n, x;

    cout << "Enter number of houses: ";
    cin >> n;

    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    cout << "Maximum money that can be robbed: "
         << obj.rob(nums) << endl;

    return 0;
}