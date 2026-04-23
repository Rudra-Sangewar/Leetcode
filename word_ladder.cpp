#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // if endWord not present, no transformation possible
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            // process each level
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return steps;

                // try all possible single-letter changes
                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;

                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word); // mark visited
                        }
                    }

                    word[j] = originalChar;
                }
            }
            steps++;
        }

        return 0;
    }
};

int main() {
    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int result = obj.ladderLength(beginWord, endWord, wordList);

    cout << "Shortest transformation length: " << result << endl;

    return 0;
}