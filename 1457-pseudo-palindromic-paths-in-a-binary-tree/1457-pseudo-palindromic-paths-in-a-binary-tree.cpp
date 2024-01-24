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
    int pseudoPalindromicPaths (TreeNode* root)
    {
        vector<int> freq(10, 0);
        solve(root, freq);
        
        return ans;
        
    }
    
    void solve(TreeNode* root, vector<int> freq)
    {
        freq[root->val]++;
        
        if(root->left)
            solve(root->left, freq);
        
        if(root->right)
            solve(root->right, freq);
        
        if(!root->left and !root->right)
            ans += isPseudoPalindrome(freq);
    }
    
    int isPseudoPalindrome(vector<int>& freq)
    {
        int odds = 0;
        
        for(auto x: freq)
            if(x % 2 == 1)
            {
                odds++;
                if(odds > 1)
                    return 0;
            }
        
        return 1;
    }
};