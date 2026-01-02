#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0, maxLength = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            // If character seen and is inside current window
            if (lastIndex.count(s[right]) && lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }

            lastIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring: "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
