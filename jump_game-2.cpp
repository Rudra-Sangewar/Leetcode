#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
    }

    return goal == 0;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};  // You can change this input

    if (canJump(nums)) {
        cout << "True - You can reach the last index" << endl;
    } else {
        cout << "False - You cannot reach the last index" << endl;
    }

    return 0;
}