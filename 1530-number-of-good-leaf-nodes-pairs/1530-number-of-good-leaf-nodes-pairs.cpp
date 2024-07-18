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
    int countPairs(TreeNode* root, int distance)
    {
        solve(root, distance);
        
        return ans;
        
    }
    
    vector<int> solve(TreeNode* root, int distance)
    {
        if(!root)
            return {};
        
        vector<int> left;
        vector<int> right;
        
        if(root->left)
            left = solve(root->left, distance);
        
        if(root->right)
            right = solve(root->right, distance);
        
        //find good leaf nodes
        
        for(int a: left)
            for(int b: right)
                if(a + b <= distance)
                    ans++;
        
        vector<int> res;
        
        for(int n: left)
            res.push_back(n+1);
        
        for(int n: right)
            res.push_back(n+1);
        
        if(res.empty())
            res={1};
        
        return res;
    }
};