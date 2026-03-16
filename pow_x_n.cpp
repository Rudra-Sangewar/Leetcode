#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        long long num = n;

        if (num < 0) {
            x = 1 / x;
            num = -num;
        }

        double power = 1;

        while (num) {
            if (num & 1) {
                power *= x;
            }

            x *= x;
            num >>= 1;
        }

        return power;
    }
};

int main() {
    Solution obj;

    cout << obj.myPow(2.0, 10) << endl;   // 1024
    cout << obj.myPow(2.0, -2) << endl;   // 0.25

    return 0;
}