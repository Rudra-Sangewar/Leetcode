#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x = 0, y = 0, dx = 1, dy = 0;
        vector<vector<int>> res(n, vector<int>(n, 0));

        for (int i = 0; i < n * n; i++) {
            res[y][x] = i + 1;

            // Check if next move is valid
            if (!(0 <= x + dx && x + dx < n &&
                  0 <= y + dy && y + dy < n &&
                  res[y + dy][x + dx] == 0)) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }

            x += dx;
            y += dy;
        }

        return res;        
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    vector<vector<int>> matrix = obj.generateMatrix(n);

    cout << "Spiral Matrix:\n";
    for (auto &row : matrix) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}