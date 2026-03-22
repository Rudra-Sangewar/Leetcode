#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half sorted
            if (nums[start] <= nums[mid]) {

                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }

            }
            // Right half sorted
            else {

                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }

            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int result = obj.search(nums, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}