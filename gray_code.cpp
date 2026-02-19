#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1 << n);   // avoid reallocations
        
        for (int i = 0; i < (1 << n); i++) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    vector<int> ans = obj.grayCode(n);

    cout << "Gray Code sequence:\n";
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}
