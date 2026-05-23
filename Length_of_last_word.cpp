#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int siz = s.size();
        int kount = 0;
        bool flag = false;

        for (int i = siz - 1; i >= 0; i--) {
            if (s[i] == ' ' && flag)
                break;

            if (s[i] != ' ') {
                flag = true;
                kount++;
            }
        }
        return kount;
    }
};

int main() {
    Solution obj;
    string s;
    getline(cin, s);   // input full line with spaces
    cout << obj.lengthOfLastWord(s);
    return 0;
}
