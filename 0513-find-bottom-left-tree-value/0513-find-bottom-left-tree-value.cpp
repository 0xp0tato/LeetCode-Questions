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
    map<int,vector<int>, greater<int>> m;
    int findBottomLeftValue(TreeNode* root)
    {
        solve(root, 0);
        
        return m.begin()->second[0];
    }
    
    void solve(TreeNode* root, int level)
    {
        m[level].push_back(root->val);
        
        if(root->left)
            solve(root->left, level + 1);
        
        if(root->right)
            solve(root->right, level + 1);

    }
    
    
};