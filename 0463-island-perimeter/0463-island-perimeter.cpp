class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == 1)
                    ans += 4 - (i-1 >= 0 && grid[i-1][j] ? 2 : 0) - (j-1 >= 0 && grid[i][j-1] ? 2 : 0);
        
        return ans;
        
    }
};