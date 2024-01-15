class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        unordered_map<int,pair<int,int>> umap;
        
        for(auto x: matches)
        {
            int winner = x[0];
            int loser = x[1];
            
            if(umap.find(winner) == umap.end())
                umap[winner] = {0,0};
            
            if(umap.find(loser) == umap.end())
                umap[loser] = {0,0};
            
            umap[winner].first++;
            umap[loser].second++;
        }
        
        vector<vector<int>> ans(2);
        
        for(auto x: umap)
        {
            if(x.second.second == 0)
                ans[0].push_back(x.first);
            
            else if(x.second.second == 1)
                ans[1].push_back(x.first);
            
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        
        return ans;
    }
};