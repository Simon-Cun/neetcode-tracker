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
    int dfs(TreeNode* curr, bool& ret) {
        if (!curr) return -1;
        int left = dfs(curr->left, ret) + 1;
        int right = dfs(curr->right, ret) + 1;
        if ((left - right) != 1 && (left - right) != -1 && (left - right) != 0) {
            ret = false;
        }
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        dfs(root, ret);
        return ret;
    }
};
