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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root)
    {
        solve(root);
        
        return ans;
    }
    
    int solve(TreeNode* root)
    {
        int left = 0;
        int right = 0;
        
        if(!root->left && !root->right)
            return 1;
        
        if(root->left)
            left = solve(root->left);
        
        if(root->right)
            right = solve(root->right);
        
        ans = max(ans, left + right);
        
        return max(left, right) + 1;
    }
};