class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> vis;
    int minDays(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        
        vis.resize(m, vector<bool>(n, false));
        
        if(noi(grid) != 1)
            return 0;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int c = noi(grid);
                    if (c != 1) return 1;
                    grid[i][j] = 1;
                }
        
        return 2;
    }
    
    void solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j] == true)
            return;
        
        vis[i][j] = true;
        
        //left
        solve(grid, i, j-1);
        
        //right
        solve(grid, i, j+1);
        
        //up
        solve(grid, i-1, j);
        
        //down
        solve(grid, i+1, j);
    }
    
    int noi(vector<vector<int>>& grid)
    {
        rv();
        int count = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1 & !vis[i][j])
                {
                    count++;
                    solve(grid, i, j);
                }
        
        return count;
    }
    
    void rv()
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                vis[i][j] = false;
    }
};