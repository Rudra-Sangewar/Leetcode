#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = dfsHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           /
          4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution obj;

    if (obj.isBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    return 0;
}