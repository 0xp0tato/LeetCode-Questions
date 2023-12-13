class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        int ans = 0;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(mat[i][j] == 1)
                    ans += checkSpecial(i,j,mat);
        
        return ans;
    }
    
    int checkSpecial(int row, int col, vector<vector<int>>& mat)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(j == col)
                continue;
            
            if(mat[row][j] == 1)
                return 0;
        }
        
        for(int i=0;i<mat.size();i++)
        {
            if(i == row)
                continue;
            
            if(mat[i][col] == 1)
                return 0;
        }
        
        return 1;
    }
};