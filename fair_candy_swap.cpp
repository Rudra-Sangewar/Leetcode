#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& alice, vector<int>& bob) {
        int sumA = 0, sumB = 0;
        
        for (int a : alice) sumA += a;
        for (int b : bob) sumB += b;
        
        int diff = (sumB - sumA) / 2;
        
        unordered_set<int> setB(bob.begin(), bob.end());
        
        for (int a : alice) {
            if (setB.count(a + diff)) {
                return {a, a + diff};
            }
        }
        
        return {};
    }
};

int main() {
    Solution obj;

    vector<int> alice = {1, 1};
    vector<int> bob = {2, 2};

    vector<int> result = obj.fairCandySwap(alice, bob);

    if (!result.empty()) {
        cout << "Swap: " << result[0] << " with " << result[1] << endl;
    } else {
        cout << "No valid swap found" << endl;
    }

    return 0;
}