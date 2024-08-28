class Solution {
public:
    vector<pair<int,int>> cd;
    int m;
    int n;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        m = grid1.size();
        n = grid1[0].size();
        
        int ans = 0;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid2[i][j] == 1)
                {
                    cd.clear();
                    solve(i, j, grid2);
                    
                    if(isSub(grid1)) ans++;
                }
     return ans;   
    }
    
    void solve(int i, int j, vector<vector<int>>& grid2)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) return;
        
        cd.push_back({i, j});
        grid2[i][j] = 2;
        
        //left
        solve(i-1, j, grid2);
        
        //right
        solve(i+1, j, grid2);
        
        //up
        solve(i, j-1, grid2);
        
        //down
        solve(i, j+1, grid2);
    }
    
    bool isSub(vector<vector<int>>& grid1)
    {
        for(auto [i, j]: cd)
        {
            if(grid1[i][j] == 1) continue;
            
            return false;
        }
        
        return true;
    }
};