#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            res += i - nums[i];
        }

        return res;
    }
};

int main() {
    Solution obj;
    
    vector<int> nums = {3, 0, 1};  // example input
    cout << "Missing number: " << obj.missingNumber(nums) << endl;

    return 0;
}