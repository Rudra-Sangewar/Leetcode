#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;

        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        int left = 0;
        int right = filtered.size() - 1;

        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter string: ";
    getline(cin, s);

    if (obj.isPalindrome(s))
        cout << "True (It is a Palindrome)" << endl;
    else
        cout << "False (Not a Palindrome)" << endl;

    return 0;
}