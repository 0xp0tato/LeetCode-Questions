class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {    
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        
        for(vector<int> edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            
            adj[u][v] = d;
            adj[v][u] = d;
            adj[u][u] = 0;
            adj[v][v] = 0;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(adj[i][k] == INT_MAX || adj[k][j] == INT_MAX) continue;
                    
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        int ans = 0;
        int cc = n;
        
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
                if(adj[i][j] <= distanceThreshold) count++;
            
            if(count <= cc)
            {
                cc = count;
                ans = i;
            }
        }
        
        return ans;
        
        
    }
};