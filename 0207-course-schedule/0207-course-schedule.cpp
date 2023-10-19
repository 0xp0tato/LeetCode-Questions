class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;
    int ans = true;
    bool traverse[2000] = {false};
    bool canFinish(int n, vector<vector<int>>& preq)
    {   
        for(auto x: preq)
            adj[x[1]].push_back(x[0]);
        
        
        for(int i=0;i<n;i++)
            dfs(i);
        
        return ans;
        
    }
    
    void dfs(int i)
    {
        if(traverse[i] == true)
            return;
        
        if(vis.find(i) != vis.end())
        {
            ans = false;
            return;
        }
        
        vis.insert(i);
        for(auto x: adj[i])
            dfs(x);
        
        vis.erase(i);
        
        traverse[i] = true;
    }
};