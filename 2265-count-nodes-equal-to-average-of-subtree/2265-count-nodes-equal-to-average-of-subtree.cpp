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
    int ans;
    int averageOfSubtree(TreeNode* root)
    {
        solve(root);
        
        return ans;
    }
    
    pair<int,int> solve(TreeNode* root)  //{sum, number of nodes}
    {
        int sum = root->val;
        int non = 1;
        
        if(root->left)
        {
            auto temp = solve(root->left);
            sum += temp.first;
            non += temp.second;
        }
        
        if(root->right)
        {
            auto temp = solve(root->right);
            sum += temp.first;
            non += temp.second;
        }
        
        if((sum / non) == root->val)
            ans++;
        
        return {sum, non};
    }
};