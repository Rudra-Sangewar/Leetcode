#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0; // index reference
        return decode(s, i);
    }

private:
    string decode(const string& s, int& i) {
        string result = "";
        int num = 0;

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // build number
                i++;
            }
            else if (c == '[') {
                i++;
                string inner = decode(s, i); // recursive call
                for (int k = 0; k < num; k++)
                    result += inner;
                num = 0; // reset number
            }
            else if (c == ']') {
                i++; // skip ']'
                return result;
            }
            else {
                result += c; // normal character
                i++;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    string decoded = obj.decodeString(s);

    cout << "Decoded string: " << decoded << endl;

    return 0;
}