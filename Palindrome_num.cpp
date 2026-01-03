#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long reverse = 0;
        int xcopy = x;

        while (x > 0) {
            reverse = reverse * 10 + (x % 10);
            x /= 10;
        }

        return reverse == xcopy;
    }
};

int main() {
    Solution sol;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (sol.isPalindrome(x)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
