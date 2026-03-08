#include <iostream>
using namespace std;

// Definition for binary tree node
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;

        // leaf node
        if(root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {

    /*
        Example Tree
              5
            /   \
           4     8
          /     / \
         11    13  4
        /  \
       7    2

       Target Sum = 22
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    Solution obj;

    int target = 22;

    if(obj.hasPathSum(root, target))
        cout << "Path exists\n";
    else
        cout << "No path found\n";

    return 0;
}