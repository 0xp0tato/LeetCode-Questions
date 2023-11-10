class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr)
    {
        vector<int> ans;
        unordered_set<int> vis;
        int n = arr.size()+1;
        
        unordered_map<int,vector<int>> adj;
        
        for(auto &x: arr)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        int start;
        
        for(auto x: adj)
            if(x.second.size() == 1)
            {
                start = x.first;
                break;
            }
        
        ans.push_back(start);
        vis.insert(start);
        
        while(ans.size() <= n)
        {
            int last = ans.back();
            
            while(!adj[last].empty() and vis.find(adj[last].back()) != vis.end())
                adj[last].pop_back();
            
            if(adj[last].empty())
                break;
            
            
            ans.push_back(adj[last].back());
            vis.insert(adj[last].back());
            adj[last].pop_back();
        }
        
        return ans;
        
    }
};