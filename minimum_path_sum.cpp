#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        // Fill rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = sol.minPathSum(grid);
    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}