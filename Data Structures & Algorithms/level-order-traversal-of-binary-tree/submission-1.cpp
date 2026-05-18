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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<vector<int>> ret;
        while (!q.empty()) {
            vector<int> toPush;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                 cout << q.size();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                toPush.push_back(curr->val);
            }
            ret.push_back(toPush);
        }
        return ret;
    }
};
