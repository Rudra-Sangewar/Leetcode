#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;   // make it local (better practice)

        stringstream ss(path);
        string comp;

        while (getline(ss, comp, '/')) {
            if (comp == "" || comp == ".") {
                continue;
            }

            if (comp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(comp);
            }
        }

        stringstream simplifiedPath;
        for (const string& s : st) {
            simplifiedPath << "/" << s;
        }

        return simplifiedPath.str().empty() ? "/" : simplifiedPath.str();
    }
};

int main() {
    Solution sol;

    string path;
    cout << "Enter path: ";
    cin >> path;

    cout << "Simplified Path: " << sol.simplifyPath(path) << endl;

    return 0;
}
