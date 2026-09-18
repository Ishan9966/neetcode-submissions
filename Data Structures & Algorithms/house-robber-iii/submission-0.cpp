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
    vector<int> f(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        vector<int> lefty = f(root->left);
        vector<int> righty = f(root->right);

        vector<int> options = {0, 0};

        options[0] = root->val + lefty[1] + righty[1];

        options[1] = max(lefty[0], lefty[1]) + max(righty[0], righty[1]);

        return options;
    }

    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> robbed = f(root);

        return max(robbed[0], robbed[1]);
    }
};