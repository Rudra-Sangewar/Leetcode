#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 2};  // change input here

    if (obj.containsDuplicate(nums)) {
        cout << "Duplicate exists" << endl;
    } else {
        cout << "No duplicate found" << endl;
    }

    return 0;
}