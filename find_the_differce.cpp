#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        for (int i = 0; i < s.size(); i++)
            t[i + 1] += t[i] - s[i];  // Passing the diff forward
        
        return t[t.size() - 1];  // Last element stores extra char
    }
};

int main() {
    Solution obj;

    string s, t;
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    char result = obj.findTheDifference(s, t);
    cout << "Extra character is: " << result << endl;

    return 0;
}