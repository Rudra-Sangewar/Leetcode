#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto x : strs) {
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = obj.groupAnagrams(strs);
    
    for (auto group : result) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}