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
    vector<int> arr;
    void inOrder(TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        arr.push_back(node->val);
        inOrder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for (int i = 1; i < arr.size(); ++i) {
            if (arr.at(i - 1) >= arr.at(i)) {
                return false;
            }
        }
        return true;
    }
};
