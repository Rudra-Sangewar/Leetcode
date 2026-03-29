#include <iostream>
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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void recoverTree(TreeNode* root) {
        helper(root);

        // Swap incorrect nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void helper(TreeNode* node) {
        if (!node) return;

        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first)
                first = prev;
            second = node;
        }

        prev = node;

        helper(node->right);
    }
};

// Inorder traversal to check correctness
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Example tree:
              3
             / \
            1   4
               /
              2
        Nodes 2 and 3 are swapped
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution obj;

    cout << "Before fix (Inorder): ";
    inorder(root);

    obj.recoverTree(root);

    cout << "\nAfter fix (Inorder): ";
    inorder(root);

    return 0;
}