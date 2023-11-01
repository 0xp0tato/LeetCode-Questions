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
    int currEle = INT_MIN;
    int currFreq = 0;
    int maxFreq = 0;
    vector<int> ans;
    vector<int> findMode(TreeNode* root)
    {
        solve(root);
        
        return ans;
        
    }
    
    void solve(TreeNode* root)
    {
        if(root->left)
            solve(root->left);
        
        if(root->val == currEle)
            currFreq++;
        
        else
        {
            currEle = root->val;
            currFreq = 1;
        }
        
        if(currFreq == maxFreq)
        {
            ans.push_back(currEle);
        }
        
        else if(currFreq > maxFreq)
        {
            ans.clear();
            ans.push_back(currEle);
            maxFreq = currFreq;
        }
        
        if(root->right)
            solve(root->right);
    }
};