#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1;

        while (row < rows && col >= 0) {
            int cur = matrix[row][col];

            if (cur == target)
                return true;
            else if (target > cur)
                row++;
            else
                col--;
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (obj.searchMatrix(matrix, target))
        cout << "Target found ✅" << endl;
    else
        cout << "Target not found ❌" << endl;

    return 0;
}