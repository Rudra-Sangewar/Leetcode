#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        // Split string into words
        while (iss >> word) {
            words.push_back(word);
        }

        // Check length mismatch
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_set<string> seenWords;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false;
                }
            } 
            else {
                if (seenWords.count(w)) {
                    return false;
                }
                charToWord[c] = w;
                seenWords.insert(w);
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    string pattern = "abba";
    string s = "dog cat cat dog";

    if (sol.wordPattern(pattern, s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}