#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        return grid;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int x, y, k;
    cin >> x >> y >> k;

    Solution obj;
    vector<vector<int>> result = obj.reverseSubmatrix(grid, x, y, k);

    for (auto &row : result) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

