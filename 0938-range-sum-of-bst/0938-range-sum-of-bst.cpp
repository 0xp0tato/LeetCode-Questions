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
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        solve(root, low, high);
        
        return ans;
    }
    
    void solve(TreeNode* root, int low, int high)
    {
        if(low <= root->val && root->val <= high)
            ans += root->val;
        
        if(root->left)
            solve(root->left, low, high);
        
        if(root->right)
            solve(root->right, low, high);
    }
};