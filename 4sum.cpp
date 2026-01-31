#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int low = j + 1, high = n - 1;

                while (low < high) {
                    long long sum = nums[low] + nums[high];

                    if (sum < newTarget) low++;
                    else if (sum > newTarget) high--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});

                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;

                        low++;
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int target;
    cin >> target;

    auto result = sol.fourSum(nums, target);

    for (auto &q : result) {
        for (int x : q) cout << x << " ";
        cout << endl;
    }

    return 0;
}
