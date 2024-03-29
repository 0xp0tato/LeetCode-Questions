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
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> l1;
        vector<int> l2;
        
        solve(root1, l1);
        solve(root2, l2);
        
        return l1 == l2;
        
    }
    
    void solve(TreeNode* root, vector<int>& v)
    {
        if(!root->left and !root->right)
            v.push_back(root->val);
        
        if(root->left)
            solve(root->left, v);
        
        if(root->right)
            solve(root->right, v);
    }
};