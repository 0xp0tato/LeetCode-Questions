class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c)
    {
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int s = 1;
        
        int i = 0;
        vector<vector<int>> ans;
        
        while(ans.size() < rows * cols)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<s;k++)
                {
                    if(r >= 0 and r < rows and c >= 0 and c < cols)
                        ans.push_back({r, c});
                    
                    r += d[i][0];
                    c += d[i][1];
                }
                i = (i + 1) % 4;
            }
            s++;
        }
        
        return ans;
        
    }
};