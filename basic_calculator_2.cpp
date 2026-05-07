#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = 0;
        char op = '+';

        s += '+'; // extra operator to process last number

        for (char c : s) {
            if (c == ' ')
                continue;

            if (isdigit(c)) {
                n = n * 10 + (c - '0');
                continue;
            }

            if (op == '+')
                st.push(n);

            else if (op == '-')
                st.push(-n);

            else if (op == '*') {
                int top = st.top();
                st.pop();
                st.push(top * n);
            }

            else if (op == '/') {
                int top = st.top();
                st.pop();
                st.push(top / n);
            }

            op = c;
            n = 0;
        }

        int res = 0;

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter expression: ";
    getline(cin, s);

    cout << "Result = " << obj.calculate(s);

    return 0;
}