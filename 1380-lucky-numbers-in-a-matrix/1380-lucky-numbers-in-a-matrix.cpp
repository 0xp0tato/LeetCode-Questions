class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        vector<int> ans;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            int col = 0;
            int mini = INT_MAX;
            
            // find minimum number in the row
            for(int j=0;j<n;j++)
                if(matrix[i][j] < mini)
                {
                    mini = matrix[i][j];
                    col = j;
                }
            
            // check if that number is max in the column
            
            if(checkMax(col, m, mini, matrix))
                ans.push_back(mini);
        }
        
        return ans;
        
    }
    
    bool checkMax(int j, int m, int mini, vector<vector<int>> matrix)
    {
        for(int k=0;k<m;k++)
            if(matrix[k][j] > mini)
                return false;
        
        return true;
    }
};