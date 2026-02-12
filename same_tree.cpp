#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }

        return false;
    }
};

int main() {
    // Create first tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Create second tree
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    
    if (sol.isSameTree(p, q))
        cout << "Trees are identical\n";
    else
        cout << "Trees are not identical\n";

    return 0;
}
