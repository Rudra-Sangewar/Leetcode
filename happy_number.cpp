#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1 || n == 7) return true;
        else if (n < 10) return false;
        else {
            int sum = 0;
            while (n > 0) {
                int temp = n % 10;
                sum += temp * temp;
                n = n / 10;
            }
            return isHappy(sum);
        }
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (obj.isHappy(n))
        cout << n << " is a Happy Number " << endl;
    else
        cout << n << " is NOT a Happy Number " << endl;

    return 0;
}