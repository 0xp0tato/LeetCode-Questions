class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int sn, int en)
    {
        unordered_map<int, vector<pair<int,double>>> adj;
        
        for(int i=0;i<sp.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = sp[i];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<double, int>> pq;
        unordered_set<int> vis;
        
        pq.push({1.0, sn});
        
        while(!pq.empty())
        {
            auto [p, nd] = pq.top();
            pq.pop();
            
             if(nd == en) return p;
            
            vis.insert(nd);
            
            for(auto x: adj[nd])
            {
                int nnd = x.first;
                double ww = x.second;
                
                if(vis.find(nnd) == vis.end()) pq.push({ww * p, nnd});
            }
        }
        
        return 0.0;
        
        
    }
};