#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, 0, path, res);
        return res;
    }

    void dfs(TreeNode* node, int targetSum, int curSum,
             vector<int>& path, vector<vector<int>>& res) {

        if (!node) return;

        curSum += node->val;
        path.push_back(node->val);

        // check if leaf node and sum equals target
        if (!node->left && !node->right && curSum == targetSum) {
            res.push_back(path);
        }

        dfs(node->left, targetSum, curSum, path, res);
        dfs(node->right, targetSum, curSum, path, res);

        path.pop_back(); // backtracking
    }
};

int main() {
    /*
            Example Tree
                5
               / \
              4   8
             /   / \
            11  13  4
           /  \      \
          7    2      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution obj;
    int targetSum = 22;

    vector<vector<int>> result = obj.pathSum(root, targetSum);

    cout << "Paths with target sum:\n";
    for (auto &path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}