class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;
    bool isPossible = true;
    vector<bool> alreadyDone;
    vector<int> ans;
    
    vector<int> findOrder(int n, vector<vector<int>>& preq)
    {   
        alreadyDone.resize(n, false);
        for(auto x: preq)
            adj[x[1]].push_back(x[0]);
        
        for(int i=0;i<n;i++)
            dfs(i);
        
        if(!isPossible)
            return {};
        
        reverse(begin(ans), end(ans));
        
        return ans;
        
    }
    
    void dfs(int i)
    {
        if(vis.find(i) != vis.end())
        {
            isPossible = false;
            return;
        }
        
        if(!isPossible || alreadyDone[i])
            return;
        
        vis.insert(i);
        
        for(auto x: adj[i])
            dfs(x);
        
        vis.erase(i);
        alreadyDone[i] = true;
        ans.push_back(i);
    }
};