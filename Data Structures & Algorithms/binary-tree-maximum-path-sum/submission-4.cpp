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
    int ret = INT_MIN;
    int helper(TreeNode* curr) {
        if (!curr) return 0;
        int left = helper(curr->left);
        int right = helper(curr->right);
        int noSplit = curr->val + max(left, right);
        int split = curr->val + left + right;
        ret = max({ret, noSplit, split, curr->val});
        return max(curr->val, noSplit);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ret;
    }
};
