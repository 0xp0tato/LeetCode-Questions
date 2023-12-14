class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<pair<int,int>> row(rows, {0,0});
        vector<pair<int,int>> col(cols, {0,0});
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 0)
                {
                    row[i].first++;
                    col[j].first++;
                }
                
                else
                {
                    row[i].second++;
                    col[j].second++;
                }
            }
        
        vector<vector<int>> diff(rows, vector<int>(cols, 0));
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                diff[i][j] = row[i].second + col[j].second - row[i].first - col[j].first;
        
        
        return diff;
        
    }
};