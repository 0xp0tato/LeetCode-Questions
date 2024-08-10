class Solution {
public:
    int r;
    int c;
    int regionsBySlashes(vector<string>& grid)
    {
        int n = grid.size();
        
        r = 3*n;
        c = 3*n;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == ' ') continue;
                
                else if(grid[i][j] == '/')
                {
                    res[i*3][(j*3)+2] = 1;
                    res[(i*3)+1][(j*3)+1] = 1;
                    res[(i*3)+2][j*3] = 1;
                }
                
                else
                {
                    res[i*3][j*3] = 1;
                    res[(i*3)+1][(j*3)+1] = 1;
                    res[(i*3)+2][(j*3)+2] = 1;
                }
            }
        
        int ans = 0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(res[i][j] == 0)
                {
                    ans++;
                    solve(res, i, j);
                }
        
        return ans;
    }
    
    void solve(vector<vector<int>>& res, int i, int j)
    {
        if(i < 0 || i >= r || j < 0 || j >= c || res[i][j] == 2 || res[i][j] == 1)
            return;
        
        res[i][j] = 2;
        
        //left
        solve(res, i, j-1);
        
        //right
        solve(res, i, j+1);
        
        //up
        solve(res, i-1, j);
        
        //down
        solve(res, i+1, j);
    }
};