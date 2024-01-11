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
    int maxAncestorDiff(TreeNode* root)
    {
        int mini = root->val;
        int maxi = root->val;
        
        solve(root, mini, maxi);
        
        return ans;
    }
    
    void solve(TreeNode* root, int mini, int maxi)
    {
        ans = max({ans, abs(root->val - mini), abs(root->val - maxi)});
        
        mini = min(root->val, mini);
        maxi = max(root->val, maxi);
        
        if(root->left)
            solve(root->left, mini, maxi);
        
        if(root->right)
            solve(root->right, mini, maxi);
    }
};