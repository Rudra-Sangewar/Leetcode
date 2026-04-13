#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution obj;
    obj.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c << " ";
    }

    return 0;
}