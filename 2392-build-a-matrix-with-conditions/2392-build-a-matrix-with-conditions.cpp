class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        vector<int> ro = tsort(rowConditions, k);
        vector<int> co = tsort(colConditions, k);
        
        if(ro.empty() || co.empty())
            return {};
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                if(ro[i] == co[j])
                    ans[i][j] = ro[i];
        
        return ans;
    }
    
    vector<int> tsort(vector<vector<int>> v, int k)
    {
        vector<vector<int>> adj(k+1);
        vector<int> order;
        
        vector<int> vis(k+1, 0);
        bool flag = false;
        
        //create adj list
        for(auto x: v)
            adj[x[0]].push_back(x[1]);
        
        //dfs
        for(int i=1;i<=k;i++)
            if(vis[i] == 0)
            {
                dfs(i, adj, vis, order, flag);
                
                if(flag) return {};
            }
        
        reverse(order.begin(), order.end());
        
        return order;
    }
    
    void dfs(int n, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order, bool& flag)
    {
        vis[n] = 1;
        
        for(int num: adj[n])
        {
            if(vis[num] == 0)
            {
                dfs(num, adj, vis, order, flag);
                
                if(flag) return;
            }
            
            else if(vis[num] == 1)
            {
                flag = true;
                return;
            }
        }
        
        vis[n] = 2;
        
        order.push_back(n);
    }
};