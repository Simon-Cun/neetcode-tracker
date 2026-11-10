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
    bool ret = true;
    int prev = INT_MIN;
    void helper(TreeNode* curr) {
        if (!curr) return;
        helper(curr->left);
        if (prev >= curr->val) ret = false;
        prev = curr->val;
        helper(curr->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ret;
    }
};
