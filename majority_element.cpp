#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = 0;
        int majority = 0;

        for (int n : nums) {
            hash[n] = 1 + hash[n];
            if (hash[n] > majority) {
                res = n;
                majority = hash[n];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);
    cout << "Majority Element: " << result << endl;

    return 0;
}
