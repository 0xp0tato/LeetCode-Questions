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
    map<int,int> m;
    vector<int> largestValues(TreeNode* root)
    {
        if(!root)
            return {};
        
        int level = 0;
        
        solve(root, level);
        
        vector<int> ans;
        for(auto x: m)
            ans.push_back(x.second);
        
        return ans;
        
    }
    
    void solve(TreeNode* root, int level)
    {
        if(m.find(level) == m.end())
            m[level] = root->val;
        
        else
            m[level] = max(m[level], root->val);
        
        if(root->left)
            solve(root->left, level+1);
        
        if(root->right)
            solve(root->right, level+1);
    }
};