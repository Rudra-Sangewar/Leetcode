#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 1, 2, 1, 2}; // example input

    cout << obj.singleNumber(nums) << endl;

    return 0;
}