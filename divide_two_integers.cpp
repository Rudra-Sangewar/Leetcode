#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long result = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};

int main() {
    Solution sol;

    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    cout << "Quotient: " << sol.divide(dividend, divisor) << endl;

    return 0;
}
