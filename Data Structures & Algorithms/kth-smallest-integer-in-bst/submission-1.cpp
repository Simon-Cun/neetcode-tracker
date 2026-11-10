/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ret = 0;
    void helper(TreeNode* curr, int& k) {
        if (!curr) return;
        helper(curr->left, k);
        --k;
        if (k == 0) ret = curr->val;
        helper(curr->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ret;
    }
};
