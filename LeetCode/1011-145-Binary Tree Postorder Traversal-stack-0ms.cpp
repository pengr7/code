/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        sta.push(root);
        while (!sta.empty()) {
            TreeNode* curr = sta.top();
            sta.pop();
            if (curr) {
                sta.push(curr->left);
                sta.push(curr->right);
                res.push_back(curr->val);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
