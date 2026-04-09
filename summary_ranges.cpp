#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if (nums.empty()) {
            return result;
        }

        for (int i = 0; i < nums.size();) {
            int start = nums[i];
            int j = i;

            // Expand range while consecutive numbers exist
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                j++;
            }

            // Store range
            if (nums[j] == start) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[j]));
            }

            i = j + 1;
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {0, 1, 2, 4, 5, 7};

    vector<string> result = obj.summaryRanges(nums);

    cout << "Summary Ranges:\n";
    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}