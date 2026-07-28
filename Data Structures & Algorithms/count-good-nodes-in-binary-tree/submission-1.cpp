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
    int helper(TreeNode* root, int ans,int currMax) {
        if (!root) return 0;

        int curr=0;
        if(root->val>=currMax){
            curr=1;
            currMax=root->val; 
        }
        int l=helper(root->left,ans,currMax);
        int r=helper(root->right,ans,currMax);
        return l+r+curr;
    }
    int goodNodes(TreeNode* root) { 
        return helper(root, 0,-101); 
    }
};
