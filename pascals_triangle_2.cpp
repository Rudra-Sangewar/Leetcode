#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);
        long long prev = 1;

        for (int k = 1; k <= rowIndex; k++) {
            long long next_val = prev * (rowIndex - k + 1) / k;
            res.push_back(next_val);
            prev = next_val;
        }

        return res;
    }
};

int main() {
    Solution sol;
    int rowIndex;

    cout << "Enter row index: ";
    cin >> rowIndex;

    vector<int> result = sol.getRow(rowIndex);

    cout << "Pascal Row: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}