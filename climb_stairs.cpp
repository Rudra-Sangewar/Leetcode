#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;

        int prev1 = 3; // ways to reach step 3
        int prev2 = 2; // ways to reach step 2
        int cur = 0;

        for (int i = 3; i < n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return cur;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Number of ways: " << obj.climbStairs(n) << endl;
    return 0;
}
