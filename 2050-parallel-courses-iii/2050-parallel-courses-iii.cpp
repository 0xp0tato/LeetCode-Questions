class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
    {
        for(auto &x: relations) // make graph 0 indexed.
        {
            x[0] = x[0] - 1;
            x[1] = x[1] - 1;
        }
        
        unordered_map<int,int> in;
        unordered_map<int,vector<int>> adj;
        
        for(auto x: relations)
        {
            in[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        
        queue<int> q;
        vector<int>maxTime(n, 0);
        
        for(int i=0;i<n;i++)
            if(in.find(i) == in.end())
            {
                q.push(i);
                maxTime[i] = time[i];
            }
        
        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            
            for(auto x: adj[num])
            {
                maxTime[x] = max(maxTime[x], maxTime[num] + time[x]);
                
                in[x]--;
                if(in[x] == 0)
                    q.push(x);
                    
            }
            
        }
        
        return *max_element(maxTime.begin(), maxTime.end());
        
    }
};