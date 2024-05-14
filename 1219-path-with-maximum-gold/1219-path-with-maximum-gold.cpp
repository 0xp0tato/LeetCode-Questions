class Solution {
public:
    int m;
    int n;
    int getMaximumGold(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != 0)
                    ans = max(ans, solve(i,j,grid));
            }
        
        return ans;
    }
    
    int solve(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        int ans = temp + max({
            solve(i + 1, j, grid),
            solve(i - 1, j, grid),
            solve(i, j + 1, grid),
            solve(i, j - 1, grid)
        });
        
        grid[i][j] = temp;
        
        return ans;
    }
};