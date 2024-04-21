class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        unordered_map<int,vector<int>> adj;
        
        for(vector<int> x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        unordered_set<int> uset;
        queue<int> q;
        
        q.push(source);
        uset.insert(source);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            if(curr == destination)
                return true;
            
            for(int x: adj[curr])
                if(uset.find(x) == uset.end())
                {
                    uset.insert(x);
                    q.push(x);
                }
        }
        
        return false;
        
    }
};