#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> counter;

        for (char ch : s) {
            counter[ch]++;
        }

        for (char ch : t) {
            if (counter.find(ch) == counter.end() || counter[ch] == 0) {
                return false;
            }
            counter[ch]--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (sol.isAnagram(s, t)) {
        cout << "Strings are anagrams ✅" << endl;
    } else {
        cout << "Strings are NOT anagrams ❌" << endl;
    }

    return 0;
}