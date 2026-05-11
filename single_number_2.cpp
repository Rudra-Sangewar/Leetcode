#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;

        // Count frequency of each number
        for (auto x : nums) {
            m[x]++;
        }

        // Find the number that appears once
        for (auto x : m) {
            if (x.second == 1) {
                return x.first;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single Number: " << obj.singleNumber(nums);

    return 0;
}