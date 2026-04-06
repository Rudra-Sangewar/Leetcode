#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPowerOfThree(n))
        cout << "True: It is a power of 3" << endl;
    else
        cout << "False: It is NOT a power of 3" << endl;

    return 0;
}