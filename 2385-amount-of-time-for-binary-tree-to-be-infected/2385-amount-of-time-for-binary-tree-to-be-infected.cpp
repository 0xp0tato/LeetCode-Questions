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
    unordered_map<int,unordered_set<int>> graph;
    
    int amountOfTime(TreeNode* root, int start)
    {
        solve(root);

        unordered_set<int> vis;
        queue<int> q;
        int ans = 0;
        
        q.push(start);
        vis.insert(start);
        
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                int f = q.front();
                q.pop();
                for(auto x: graph[f])
                    if(vis.find(x) == vis.end())
                    {
                        q.push(x);
                        vis.insert(x);
                    }
            }
            
            ans++;
        }
        
        return ans-1;
        
    }
    
    void solve(TreeNode* root)
    {
        if(root->left)
        {
            graph[root->val].insert(root->left->val);
            graph[root->left->val].insert(root->val);
            solve(root->left);
        }
        
        if(root->right)
        {
            graph[root->val].insert(root->right->val);
            graph[root->right->val].insert(root->val);
            solve(root->right);
        }
    }
};